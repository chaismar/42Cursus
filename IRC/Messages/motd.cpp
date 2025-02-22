#include "../header.hpp"
#include "../Server.hpp"

void print_motd(Client &cli)
{
	std::string notice = ":" + std::string(IRCNAME) + " NOTICE " + cli.get_nickname() + ": *** Notice -- motd was last changed at 20/10/2024\r\n";
	send_messages(cli.get_socket_client(), notice);
	send_messages(cli.get_socket_client(), MOTD_START(cli.get_nickname()));
	send_messages(cli.get_socket_client(), MOTD_1(cli.get_nickname()));
	send_messages(cli.get_socket_client(), MOTD_2(cli.get_nickname()));
	send_messages(cli.get_socket_client(), MOTD_END(cli.get_nickname()));
}

void Server::motd(const ParsedMessage& msg, Client &cli)
{
	if (msg.params.empty())
		print_motd(cli);
	else
		send_messages(cli.get_socket_client(), ERR_NOSUCHSERVER(cli.get_nickname()));
}