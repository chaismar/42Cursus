#include "../header.hpp"
#include "../Server.hpp"


void Server::ping(const ParsedMessage &msg, Client &cli)
{
	std::string pong = ":" + std::string(IRCNAME) + " PONG " +  msg.params[0] + " :" + cli.get_nickname() + "\r\n";
	send_messages(cli.get_socket_client(), pong);
}