#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

int check_topic(const ParsedMessage& msg, Client& cli, const std::vector<Channel>& channels) {
	if (msg.params.empty())
		return (send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("TOPIC"))), 0;
	
	std::string channel_name = msg.params[0];

	//verif si le canal existe et si le client est dedans
	for (std::vector<Channel>::const_iterator it = channels.begin(); it != channels.end(); ++it) {
		if (it->getName() == channel_name) {
			if (!it->isClientInChannel(cli.get_socket_client()))
				return send_messages(cli.get_socket_client(), ERR_NOTONCHANNEL(cli.get_nickname(), channel_name)), 0;
			return 1;
		}
	}

	send_messages(cli.get_socket_client(), ERR_NOSUCHCHANNEL(cli.get_nickname(), channel_name));
	return 0;
}

void Server::topic(const ParsedMessage& msg, Client& cli) {
	if (!check_topic(msg, cli, _channels))
		return;
	
	std::string channel_name = msg.params[0];
	std::string new_topic = msg.trailing;

	// chercher le canal et recuperer son iterateur
	std::vector<Channel>::iterator it = _channels.end();
	for (std::vector<Channel>::iterator iter = _channels.begin(); iter != _channels.end(); ++iter) {
		if (iter->getName() == channel_name) {
			it = iter;
			break;
		}
	}

    if (new_topic.empty() && !msg.has_colon) {
        if (it->getTopic().empty()) {
            send_messages(cli.get_socket_client(), RPL_NOTOPIC(cli.get_nickname(), channel_name));
			if (!it->getTopicSetter().empty())
				send_messages(cli.get_socket_client(), RPL_TOPICWHOTIME(cli.get_nickname(), channel_name, it->getTopicSetter(), it->getTopicSetTime(), it->getTopicMask()));
        } else {
            send_messages(cli.get_socket_client(), RPL_TOPIC(cli.get_nickname(), channel_name, it->getTopic()));
			send_messages(cli.get_socket_client(), RPL_TOPICWHOTIME(cli.get_nickname(), channel_name, it->getTopicSetter(), it->getTopicSetTime(), it->getTopicMask()));
        }
        return;
    }

    // Si le mode `t` est activé et que le client n'est pas opérateur, il ne peut pas changer le sujet
    if (it->isTopicRestricted() && !it->isOperator(cli.get_socket_client())) {
        send_messages(cli.get_socket_client(), ERR_CHANOPRIVSNEEDED(cli.get_nickname(), channel_name));
        return;
    }

    // Modifier ou effacer le sujet
    if (new_topic.empty() && msg.has_colon) {
        it->setTopic("", cli.get_nickname(), cli.get_nickmask());
        std::string topic_message = ":" + cli.get_nickmask() + " TOPIC " + channel_name + " :\r\n";
        send_messages(it->getClients(), topic_message);
        std::cout << "Topic cleared for channel " << channel_name << std::endl;
    } else {
        // Sinon, on définit le nouveau sujet
        it->setTopic(new_topic, cli.get_nickname(), cli.get_nickmask());
        std::string topic_message = ":" + cli.get_nickmask() + " TOPIC " + channel_name + " :" + new_topic + "\r\n";
        send_messages(it->getClients(), topic_message);
        std::cout << "Topic set for channel " << channel_name << ": " << new_topic << std::endl;
    }
}
