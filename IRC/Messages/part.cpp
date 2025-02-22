#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

int check_part(const ParsedMessage& msg, Client& cli) {
	if (msg.params.empty()) {
		send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS_JOIN());
		return 0;
	}
	return 1;
}

void Server::part(const ParsedMessage& msg, Client& cli) {
    if (!check_part(msg, cli))
        return;

    std::string reason = msg.trailing.empty() ? "Left the channel" : msg.trailing;

    // Extraire les noms des canaux séparés par des virgules
    std::vector<std::string> channel_names;
    std::istringstream channel_stream(msg.params[0]);
    std::string channel_name;
    while (std::getline(channel_stream, channel_name, ',')) {
        channel_names.push_back(channel_name);
    }

    for (size_t i = 0; i < channel_names.size(); ++i) {
        channel_name = channel_names[i];

        // Trouver le canal dans la liste des canaux
        std::vector<Channel>::iterator it = this->_channels.end();
        for (std::vector<Channel>::iterator iter = this->_channels.begin(); iter != this->_channels.end(); ++iter) {
            if (iter->getName() == channel_name) {
                it = iter;
                break;
            }
        }

        // Si le canal n'existe pas, envoyer l'erreur ERR_NOSUCHCHANNEL
        if (it == this->_channels.end()) {
            send_messages(cli.get_socket_client(), ERR_NOSUCHCHANNEL(cli.get_nickname(), channel_name));
            continue;
        }

        // Si le client n'est pas sur le canal, envoyer l'erreur ERR_NOTONCHANNEL
        if (!it->isClientInChannel(cli.get_socket_client())) {
            send_messages(cli.get_socket_client(), ERR_NOTONCHANNEL(cli.get_nickname(), channel_name));
            continue;
        }

        // Envoyer le message PART à tous les clients du canal
        std::string part_message = ":" + cli.get_nickmask() + " PART " + channel_name + " :" + reason + "\r\n";
        std::vector<int> clients_fds = it->getClients();
        send_messages(clients_fds, part_message);

        // Retirer le client du canal
        it->removeClient(cli.get_socket_client());
        std::cout << cli.get_nickname() << " left the channel: " << channel_name << std::endl;

        // Si le canal est vide après le départ du client, le supprimer
        if (it->getClients().empty()) {
            this->_channels.erase(it);
            std::cout << "Channel " << channel_name << " has been removed due to no users left." << std::endl;
        }
    }
}