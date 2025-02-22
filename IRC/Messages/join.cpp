#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

std::string convertToString(long num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

bool isChannelNameEqual(const Channel &ch, const std::string &name) {
	return ch.getName() == name;
}

int check_join(const ParsedMessage& msg, Client& cli) {
	if (cli.get_nickname() == "*")
		return send_messages(cli.get_socket_client(), ERR_NONICKNAMEGIVEN()), 0;
		
	if (msg.params.empty())
		return send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("JOIN")), 0;
	return 1;
}

void Server::join(const ParsedMessage& msg, Client& cli) {
	if (!check_join(msg, cli))
		return;
		
    std::vector<std::string> channel_names;
    std::istringstream channel_stream(msg.params[0]);
    std::string channel_name;
    while (std::getline(channel_stream, channel_name, ',')) {
        channel_names.push_back(channel_name);
    }

    // Séparer les mots de passe par des virgules s'ils existent
    std::vector<std::string> passwords;
    if (msg.params.size() > 1) {
        std::istringstream password_stream(msg.params[1]);
        std::string password;
        while (std::getline(password_stream, password, ',')) {
            passwords.push_back(password);
        }
    }

    for (size_t i = 0; i < channel_names.size(); ++i) {
        channel_name = channel_names[i];
        std::string password = (i < passwords.size()) ? passwords[i] : "";

        if (!Channel::isValidChannelName(channel_name)) {
            send_messages(cli.get_socket_client(), ERR_BADCHANMASK(cli.get_nickname(), channel_name));
            continue;
        }

        // Chercher si le canal existe déjà
        std::vector<Channel>::iterator it = this->_channels.end();
        for (std::vector<Channel>::iterator iter = this->_channels.begin(); iter != this->_channels.end(); ++iter) {
            if (iter->getName() == channel_name) {
                it = iter;
                break;
            }
        }

        // Si le canal n'existe pas, on le crée
        if (it == _channels.end()) {
            Channel new_channel(channel_name);
            new_channel.addClient(cli.get_socket_client());
            new_channel.addOperator(cli.get_socket_client());
            _channels.push_back(new_channel);
            it = _channels.end() - 1; // Pointe vers le nouveau canal créé
            std::cout << "New channel created: " << channel_name 
                      << " with operator " << cli.get_nickname() << std::endl;
        }

        // Sinon, on rejoint le canal existant
        else {
            // Vérifier le mode invite-only
            if (it->isInviteOnly() && !it->isInvited(cli.get_socket_client())) {
                send_messages(cli.get_socket_client(), ERR_INVITEONLYCHAN(cli.get_nickname(), channel_name));
                continue;
            }

            // Vérifier le mode client-limit
            if (it->getClientLimit() > 0 && it->getClients().size() >= static_cast<size_t>(it->getClientLimit())) {
                send_messages(cli.get_socket_client(), ERR_CHANNELISFULL(cli.get_nickname(), channel_name));
                continue;
            }

            // Vérifier si le canal a un mot de passe défini (key)
            if (!it->getKey().empty() && it->getKey() != password) {
                send_messages(cli.get_socket_client(), ERR_BADCHANNELKEY(cli.get_nickname(), channel_name));
                continue;
            }

            // Ajouter le client au canal
            it->addClient(cli.get_socket_client());
            std::cout << cli.get_nickname() << " joined the channel: " << channel_name << std::endl;

        	it->removeInvite(cli.get_socket_client());
        }

        // Message JOIN pour l'envoyer aux autres membres du canal
        std::string join_message = ":" + cli.get_nickmask() + " JOIN :" + channel_name + "\r\n";
        std::vector<int> clients_fds = it->getClients();
        send_messages(clients_fds, join_message);

        // Envoyer le topic actuel, s'il est défini
        if (!it->getTopic().empty()) {
            send_messages(cli.get_socket_client(), RPL_TOPIC(cli.get_nickname(), channel_name, it->getTopic()));
			send_messages(cli.get_socket_client(), RPL_TOPICWHOTIME(cli.get_nickname(), channel_name, it->getTopicSetter(), it->getTopicSetTime(), it->getTopicMask()));
		}
  
		std::string names_list = it->getNamesList(_clients);
		send_messages(cli.get_socket_client(), RPL_NAMREPLY(cli.get_nickname(), channel_name, names_list));
		send_messages(cli.get_socket_client(), RPL_ENDOFNAMES(cli.get_nickname(), channel_name));

		send_messages(cli.get_socket_client(), RPL_CREATIONTIME(cli.get_nickname(), channel_name, it->getCreationTime()));

    	}
}