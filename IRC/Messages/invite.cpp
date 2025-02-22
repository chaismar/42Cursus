#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

void Server::invite(const ParsedMessage& msg, Client& cli) {
    if (msg.params.size() < 2)
        return send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("INVITE"));

    std::string nickname = msg.params[0];
    std::string channel_name = msg.params[1];

    // Recherche du canal et du client
    Channel* target_channel = findChannel(channel_name);
    if (!target_channel)
        return send_messages(cli.get_socket_client(), ERR_NOSUCHCHANNEL(cli.get_nickname(), channel_name));

    if (!target_channel->isClientInChannel(cli.get_socket_client()))
        return send_messages(cli.get_socket_client(), ERR_NOTONCHANNEL(cli.get_nickname(), channel_name));

    Client* invited_client = findClient(nickname);
    if (!invited_client)
        return send_messages(cli.get_socket_client(), ERR_NOSUCHNICK(nickname));

    if (target_channel->isClientInChannel(invited_client->get_socket_client()))
        return send_messages(cli.get_socket_client(), ERR_USERONCHANNEL(nickname, channel_name));

  	// Ajouter l'utilisateur à la liste des invités et envoyer les messages
    target_channel->addInvite(invited_client->get_socket_client());
    

    send_messages(cli.get_socket_client(), RPL_INVITING(cli.get_nickname(), invited_client->get_nickname(), channel_name));

    std::string invite_message = ":" + cli.get_nickmask() + " INVITE " + invited_client->get_nickname() + " :" + target_channel->getName() + "\r\n";
    send_messages(invited_client->get_socket_client(), invite_message);

	std::string notice_message = ":" + cli.get_nickmask() + " NOTICE " + target_channel->getName() + " :" + cli.get_nickname() + " invited " + invited_client->get_nickname() + " into channel " + target_channel->getName() + "\r\n";
    send_messages(target_channel->getClients(), notice_message);

    std::cout << cli.get_nickname() << " invited " << invited_client->get_nickname() << " to join " << target_channel->getName() << std::endl;
}
