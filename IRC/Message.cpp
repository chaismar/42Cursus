#include "header.hpp"
#include "Server.hpp"

void send_messages(int fd, const std::string& message) {
    if (send(fd, message.c_str(), message.size(), 0) == -1) {
        std::cerr << "Erreur lors de l'envoi du message au fd: " << fd << std::endl;
    } else {
        std::cout << color_violet <<"Reponse envoyé a " << fd << ": "<< color_reset << message;
    }
}

void send_messages(std::vector<Client *>& cli, const std::string& message) {
    for (std::size_t i = 0; i < cli.size(); ++i) {
        if (send(cli[i]->get_socket_client(), message.c_str(), message.size(), 0) == -1) {
            std::cerr << "Erreur lors de l'envoi du message au fd: " << cli[i]->get_socket_client() << std::endl;
        } else {
            std::cout << "Reponse envoyé au fd: " << cli[i]->get_socket_client() << " " << message;
        }
    }
}

void send_messages(const std::vector<int>& fd, const std::string& message) {
    for (std::size_t i = 0; i < fd.size(); ++i) {
        if (send(fd[i], message.c_str(), message.size(), 0) == -1) {
            std::cerr << "Erreur lors de l'envoi du message au fd: " << fd[i] << std::endl;
        } else {
            std::cout << "Reponse envoyé au fd: " << fd[i] << " " << message;
        }
    }
}

int check_char(char c, const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

int check_string(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str2.size(); ++i) {
        if (str1.find(str2[i]) != std::string::npos) {
            return 1;
        }
    }
    return 0;
}

int check_special(const std::string& input) {
    // Vérifie si une séquence d'échappement commence
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == 27) { // 27 correspond à ESC
            // Vérifie s'il reste suffisamment de caractères pour former une séquence d'échappement
        	if (i + 2 < input.size() && input[i + 1] == '[')
				return 1;
		}
    }
    return 0;
}

int isNumeric(const std::string& str) {
    if (str.empty()) return false; // Handle empty string case
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) return 0;
    }
    return 1;
}

ParsedMessage parseMessage(const std::string& message) {
	ParsedMessage parsed;
	std::istringstream stream(message);
	std::string segment;

	// Lire le préfixe s'il existe
	if (message[0] == ':') {
		std::getline(stream, segment, ' ');
		parsed.prefix = segment.substr(1); // Enlever le ':'
	}

	// Lire la commande
	std::getline(stream, segment, ' ');
	parsed.command = segment;

	parsed.has_colon = false;

	// Lire les paramètres jusqu'à atteindre le trailing
	while (std::getline(stream, segment, ' ')) {
        if (segment[0] == ':') {
			parsed.has_colon = true;
            std::string rest_of_line;
            std::getline(stream, rest_of_line);

            // Concaténer le segment initial (enlevant le ':'), avec le reste
            parsed.trailing = segment.substr(1) + (rest_of_line.empty() ? "" : " " + rest_of_line);
            break;
        }
		parsed.params.push_back(segment);
	}
	return parsed;
}

// Fonction qui parse plusieurs messages
std::vector<ParsedMessage> parseMessages(const std::string& messages) {
	std::vector<ParsedMessage> parsedMessages;
	std::istringstream stream(messages);
	std::string line;

	// Lire chaque ligne séparée par \r\n
	while (std::getline(stream, line)) {
		// Si on trouve un '\r', on coupe la ligne ici
		if (line.find('\r') != std::string::npos) {
			line = line.substr(0, line.find('\r')); // Enlever le '\r'
		}
		// Vérifier si la ligne n'est pas vide
		if (!line.empty()) {
			ParsedMessage parsed = parseMessage(line);
			parsedMessages.push_back(parsed);
		}
	}

	return parsedMessages;
}

/*
- faire une map de pointeur sur fonction avec la value en maj et en min
*/

void Server::connect_msg(Client &cli)
{
	cli.set_logged();
	send_messages(cli.get_socket_client(), RPL_WELCOME(cli.get_nickname()));
	send_messages(cli.get_socket_client(), RPL_YOURHOST(cli.get_nickname()));
	send_messages(cli.get_socket_client(), RPL_CREATED(cli.get_nickname(), this->get_datetime(_datetime)));
	std::cout << color_green << "Messages de bienvenue envoyé au client " << cli.get_socket_client() << ": " << RPL_WELCOME(cli.get_nickname()) << color_reset;
	print_motd(cli);
}

void Server::handleCommand(const ParsedMessage& msg, Client &cli) {
	if (msg.command == "QUIT") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		quit(msg, cli);
  	} else if (msg.command == "PASS") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		pass(msg, _pwd, cli);
  	} else if (cli.get_passed() == false) {
		send_messages(cli.get_socket_client(), ERR_NOTREGISTERED);
	} else if (msg.command == "NICK") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		nick(msg, cli, _clients);
	} else if (msg.command == "USER") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		user(msg, cli);
  	} else if (cli.get_logged() == false){
		send_messages(cli.get_socket_client(), ERR_NOTREGISTERED);
	} else if (msg.command == "PART") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		part(msg, cli);
	} else if (msg.command == "PING") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		ping(msg, cli);
  	} else if (msg.command == "JOIN") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		join(msg, cli);
  	} else if (msg.command == "PRIVMSG") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		privmsg(msg, cli);
  	} else if (msg.command == "TOPIC") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		topic(msg, cli);
  	} else if (msg.command == "KICK") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		kick(msg, cli);
	} else if (msg.command == "MODE") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		mode(msg, cli);
	} else if (msg.command == "INVITE") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		invite(msg, cli);
	} else if (msg.command == "WHOIS") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		whois(msg, cli, _clients);
	} else if (msg.command == "motd") {
		std::cout << color_orange << "|" << msg.command << " called"<< color_reset << std::endl;
		motd(msg, cli);
	} else {
		std::cout << "Unknown command: "  << "|" << msg.command << std::endl;
	}
}

//modif pour traiter les messages avec ctrl+D (attendre un /n pour envoyer un message)
//buffer message dans Client ? et si il y a un \n on le traite

void Server::handleIncomingMessages(const std::string& buffer, int fd) {
	Client &cli = getClient(fd);
	cli.set_buffer(buffer);
	if (cli.get_buffer().find("\n") == std::string::npos)
		return ;
	std::vector<ParsedMessage> commands = parseMessages(cli.get_buffer());
	for (size_t i = 0; i < commands.size(); ++i) {
		handleCommand(commands[i], cli); // Appeler votre fonction pour traiter chaque commande
		if (!commands[i].command.empty() && commands[i].command == "QUIT")
			return ;
	}
	if (clientExist(fd) == true)
		cli.reset_buffer();
}
