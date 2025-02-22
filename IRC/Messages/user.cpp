#include "../header.hpp"
#include "../Server.hpp"

int	check_user(const ParsedMessage& msg, Client &cli)
{
	if (cli.get_nickname() == "*")
		return send_messages(cli.get_socket_client(), ERR_NONICKNAMEGIVEN()), 0;
	if (!cli.get_username().empty())
		return send_messages(cli.get_socket_client(), ERR_ALREADYREGISTERED(msg.command)) , 0;
	if (msg.params.empty() || msg.params.size() < 3 || check_special(msg.params[0]) || check_special(msg.params[1]) || check_special(msg.params[2]))
		return send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS(msg.command)), 0;
	return 1;
}

void Server::user(const ParsedMessage& msg, Client &cli)
{
	if (check_user(msg, cli))
	{
		cli.set_username(msg.params[0]);
		cli.set_hostname(msg.params[2]);
		cli.set_realname(msg.trailing);
		cli.set_named();
	}
	if (cli.get_nicked() == true && cli.get_named() == true && cli.get_logged() == false)
		connect_msg(cli);
}