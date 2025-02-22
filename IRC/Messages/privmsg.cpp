#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

int check_privmsg(const ParsedMessage& msg, Client &cli) {
    if (msg.params.empty() || msg.params[0].empty()) {
        send_messages(cli.get_socket_client(), ERR_NORECIPIENT(cli.get_nickname()));
        return 0;
    }
    if (msg.trailing.empty()) {
        send_messages(cli.get_socket_client(), ERR_NOTEXTTOSEND(cli.get_nickname()));
        return 0;
    }
    return 1;
}

void Server::privmsg(const ParsedMessage& msg, Client &cli) {
    if (!check_privmsg(msg, cli))
		return;

    std::string target = msg.params[0];
    std::string message = msg.trailing;
    std::string formatted_message = ":" + cli.get_nickmask() + " PRIVMSG " + target + " :" + message + "\r\n";
	std::string private_message = ":" + cli.get_nickname() + " PRIVMSG " + target + " :" + message + "\r\n";

    // Chercher si la cible est un client
    for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if ((*it)->get_nickname() == target) {
            send_messages((*it)->get_socket_client(), formatted_message);
            return;
        }
    }

    // Chercher si la cible est un channel
    for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
        if (it->getName() == target) {
			// Vérifier que l'expéditeur est membre du canal
            if (!it->isClientInChannel(cli.get_socket_client()))
                return send_messages(cli.get_socket_client(), ERR_CANNOTSENDTOCHAN(cli.get_nickname(), target));

            // Envoyer le message à tous les membres du canal
            std::vector<int> clients_fds = it->getClients();
            for (std::vector<int>::iterator iter = clients_fds.begin(); iter != clients_fds.end(); ++iter) {
                if (*iter != cli.get_socket_client())
                    send_messages(*iter, formatted_message);
            }
            return;
        }
    }

    // Si la cible n'existe ni comme client ni comme channel
    send_messages(cli.get_socket_client(), "401 " + cli.get_nickname() + " " + target + " :No such nick/channel\r\n");
}