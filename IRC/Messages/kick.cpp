#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

void Server::kick(const ParsedMessage& msg, Client& cli) {
	if (msg.params.size() < 2)
		return send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("KICK"));
	
	std::string channel_name = msg.params[0];
	std::string target_nickname = msg.params[1];
	std::string reason = msg.trailing.empty() ? cli.get_nickname() : msg.trailing;


	// Rechercher le channel
	Channel* target_channel = findChannel(channel_name);
	if (!target_channel)
		return send_messages(cli.get_socket_client(), ERR_NOSUCHCHANNEL(cli.get_nickname(), channel_name));
	
	// verifier si le client est dans le channel
	if (!target_channel->isClientInChannel(cli.get_socket_client()))
		return send_messages(cli.get_socket_client(), ERR_NOTONCHANNEL(cli.get_nickname(), channel_name));
	
	if (!target_channel->isOperator(cli.get_socket_client()))
		return send_messages(cli.get_socket_client(), ERR_CHANOPRIVSNEEDED(cli.get_nickname(), channel_name));
	
	// verifier si la cible existe
	Client* target_client = findClient(target_nickname);
	if (!target_client)
		return send_messages(cli.get_socket_client(), ERR_NOSUCHNICK(target_nickname));
	
	// verifier si la cible est dans le channel
	if  (!target_channel->isClientInChannel(target_client->get_socket_client()))
		return send_messages(cli.get_socket_client(), ERR_USERNOTINCHANNEL(target_nickname, channel_name));

	std::string kick_message = ":" + cli.get_nickmask() + " KICK " + channel_name + " " + target_client->get_nickname() + " :" + reason + "\r\n";

	std::vector<int> clients_fds = target_channel->getClients();
	send_messages(clients_fds, kick_message);

	target_channel->removeClient(target_client->get_socket_client());

	std::cout << cli.get_nickname() << " kicked " << target_client->get_nickname() << " from " << channel_name << " for reason: " << reason << std::endl;
}