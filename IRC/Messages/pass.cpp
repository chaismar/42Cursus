#include "../header.hpp"
#include "../Server.hpp"

int check_pass(const ParsedMessage &msg, std::string &pwd, Client &cli)
{
	if (cli.get_logged() == true)
		return send_messages(cli.get_socket_client(), ERR_ALREADYREGISTERED(msg.command)), 0;
	if (msg.params.empty())
		return send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS(msg.command)), 0;
	if (msg.params[0] != pwd)
		return send_messages(cli.get_socket_client(), ERR_PASSWDMISMATCH()), 0;
	return 1;
}

void Server::pass(const ParsedMessage &msg, std::string &pwd, Client &cli)
{
	if (check_pass(msg, pwd, cli)){
		cli.set_passed();
	}
}