#include "../header.hpp"
#include "../Server.hpp"

void Server::quit(const ParsedMessage& msg, Client &cli)
{
	std::string s;
	std::cout << color_red << "Deconnexion client : " << cli.get_socket_client() << color_reset << std::endl; // Si le client s'est déconnecte
	if (msg.params.empty() || msg.params[0].empty())
		s = " ";
	else
		s = msg.params[0];
	checkChannel(cli.get_socket_client());
	epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, cli.get_socket_client(), 0);
	erase_client(_clients, cli.get_socket_client());
}