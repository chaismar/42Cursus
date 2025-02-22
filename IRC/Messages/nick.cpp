#include "../header.hpp"
#include "../Server.hpp"

std::string genRandomNick(){
	const int length = 8;
	const std::string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string randomString;
    srand(time(0));  // Initialise le générateur de nombres aléatoires

    for (size_t i = 0; i < length; ++i) {
        randomString += characters[rand() % characters.size()];
    }

    return randomString;
}

int check_nick(const ParsedMessage& msg, std::vector<Client *> &clients, Client cli)
{
	if (msg.params.empty() || msg.params[0].empty())
	{
		return send_messages(cli.get_socket_client(), ERR_NONICKNAMEGIVEN()), -1;
	}
	if (msg.params.size() > 1 || msg.params[0].size() > 9 || check_char(msg.params[0][0], " $:#&!~%+") || check_string(msg.params[0], " \'\",*?!@.") || check_special(msg.params[0])){
			return send_messages(cli.get_socket_client(), ERR_ERRONEUSNICKNAME(cli.get_nickname())) , 0;
	}
	for (size_t i = 0; i < clients.size(); i++)
	{
		if (clients[i]->get_nickname() == msg.params[0])
		{
			std::string rdm_nick = genRandomNick();
		
			cli.set_nickname(rdm_nick);
			cli.set_nicked();
			return send_messages(cli.get_socket_client(), ERR_NICKNAMEINUSE(msg.params[0], cli.get_nickname())), 0;
		}
	}
	return 1;
}

void Server::nick(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients)
{
	if (check_nick(msg, clients, cli )){
		send_messages(cli.get_socket_client(), RPL_NICK(cli.get_nickmask(), msg.params[0]));
		cli.set_nickname(msg.params[0]);
		cli.set_nicked();
	}
	if (cli.get_nicked() == true && cli.get_named() == true && cli.get_logged() == false)
		connect_msg(cli);
}