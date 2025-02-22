#include "../header.hpp"
#include "../Server.hpp"

int check_whois(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients)
{
	if (msg.params.empty() || msg.params[0].empty())
		return send_messages(cli.get_socket_client(), ERR_NONICKNAMEGIVEN()), -1;
	if (!msg.prefix.empty())
		return send_messages(cli.get_socket_client(), ERR_NOSUCHSERVER()), -1;
	for (size_t i = 0; i < clients.size(); i++)
	{
		if (msg.params[0] == clients[i]->get_nickname())
			return i;
	}
	return send_messages(cli.get_socket_client(), ERR_NOSUCHNICK(cli.get_nickmask())), -1;
	
}

void Server::whois(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients)
{
	int index = check_whois(msg, cli, clients);
	if (index == -1)
		return ;
	send_messages(cli.get_socket_client(), RPL_WHOISUSER(cli.get_nickname(), clients[index]->get_nickname(), clients[index]->get_username(), clients[index]->get_hostname(), clients[index]->get_realname()));
	send_messages(cli.get_socket_client(), RPL_WHOISCHANNELS(cli.get_nickname(), clients[index]->get_nickname(), getChannelnamebyClient(msg)));
	//parcours la liste channel
		//si user est connect recup le name du chan
	send_messages(cli.get_socket_client(), RPL_WHOISSERVER(cli.get_nickname(), clients[index]->get_nickname()));
	send_messages(cli.get_socket_client(), RPL_ENDOFWHOIS(cli.get_nickname(), clients[index]->get_nickname()));
}

