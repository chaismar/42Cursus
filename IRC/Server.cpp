#include "Server.hpp"
#include "Message.cpp"

bool run = true;

void signalHandler(int signum) {
	signum++;;
	run = false;
    // Vous pouvez choisir d'arrêter le programme ou de faire autre chose
    // std::exit(signum); // Décommenter pour quitter le programme
}

// Fonction pour configurer un socket en mode non-bloquant
void set_nonblocking(int sockfd) {
	// Récupérer les options actuelles du socket
	int opts = fcntl(sockfd, F_SETFL, O_NONBLOCK);;
	if (opts < 0) {
		std::cerr << "Erreur lors de la récupération des options du socket" << std::endl;
		exit(-1);
	}
}

void erase_client(std::vector<Client *>& clients, int fd) {
	for (size_t i = 0; i < clients.size(); ++i) {
		if (clients[i]->get_socket_client() == fd) {
			close(fd);
			delete clients[i];
			clients.erase(clients.begin() + i);
			std::cout << "Client with fd " << fd << " removed in vector Server::Client." << std::endl;
			return; // Exit the function after removal
		}
	}
	std::cout << "Client with fd " << fd << " not found." << std::endl;
}

Server::Server(std::string pwd) {
	std::signal(SIGINT, signalHandler);
	// Création du socket serveur
	if ((_server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		throw(Server::ErrorSocketCreation());

	// Configuration des options du socket pour réutiliser l'adresse
	int opt = 1;
	if (setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
		throw(Server::ErrorSocketOption());
	}

	// Initialisation de l'adresse du serveur
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY; // Accepter des connexions de n'importe quelle interface
	_address.sin_port = htons(PORT); // Port du serveur
	_addrlen = sizeof(_address);

	// Lier le socket à l'adresse
	if (bind(_server_fd, (struct sockaddr*)&_address, sizeof(_address)) < 0)
		throw(Server::ErrorSocketLink());

	// Mise en écoute du socket pour les connexions entrantes
	if (listen(_server_fd, SOMAXCONN) < 0)
		throw(Server::ErrorSocketListen());

	// Création de l'instance epoll pour la gestion des événements
	_epoll_fd = epoll_create1(0);
	if (_epoll_fd < 0)
		throw(Server::ErrorEpollCreate());

	// Configuration de l'événement pour le socket serveur
	_ev.events = EPOLLIN;
	_ev.data.fd = _server_fd;

	// Ajout du socket serveur à l'instance epoll
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &_ev) < 0)
		throw(Server::ErrorEpollLinkToServ());
	_pwd = pwd;
	_datetime = std::time(0);
}

void Server::checkChannel(int fd){
	Client &cli = getClient(fd);
	for (size_t i = 0; i < _channels.size(); i++)
	{
		if (_channels[i].isClientInChannel(fd)){
			if (_channels[i].getNbrClients() == 1)
			{
				_channels[i].removeClient(fd);
				std::cout << "Channel " << _channels[i].getName() << " has been removed due to no users left." << std::endl;
				std::vector<Channel>::iterator it =_channels.begin() + i;
				_channels.erase(it);
			}
			else
			{
				_channels[i].removeClient(fd);
				send_messages(_channels[i].getClients(), RPL_CHANDISCONECT(cli.get_nickmask()));
			}
		}
	}
}

Server::~Server() {
	close(_server_fd);
	close(_epoll_fd);
}

// Affichage du message reçu dans le terminal
void Server::display_message(int client_fd, ssize_t length) {

	std::cout << color_blue << "Message reçu de " << client_fd << ": " << color_reset;

	for (ssize_t i = 0; i < length; ++i) {
		if (_buffer[i] == '\r') {
			std::cout << "\\r"; // Afficher un retour chariot
		} else if (_buffer[i] == '\n') {
			std::cout << "\\n"; // Afficher une nouvelle ligne
		} else {
			std::cout << _buffer[i]; // Afficher le caractère
		}
	}
	std::cout << std::endl;
}

// Boucle principale du serveur pour gérer les événements
void Server::loop() {
	while (run) {
		std::cout << "----------------------------------------------------" << std::endl;
		_event_count = epoll_wait(_epoll_fd, _events, (MAX_EVENTS), -1);
		if (_event_count < 0) {
			if (run == false)
			{
				exit_clean();
				break ;
			}
			throw ErrorEpollWait(); // Gestion des erreurs lors de l'attente d'événements
		}
		for (int i = 0; i < _event_count; i++) {
			if (_events[i].data.fd == _server_fd) { // Si c'est une nouvelle connexion
				int client_fd = accept(_server_fd, (struct sockaddr*)&_address, &_addrlen);
				if (client_fd < 0) {
					std::cerr << "Erreur lors de l'acceptation de la connexion: " << strerror(errno) << std::endl;
					continue;
				}
				set_nonblocking(client_fd);
				// Obtenir l'adresse IP du client
				char client_ip[INET_ADDRSTRLEN];
				inet_ntop(AF_INET, &(_address.sin_addr), client_ip, INET_ADDRSTRLEN);
				std::cout << color_red << "Nouvelle connexion acceptée: " << client_fd 
						  << " depuis " << client_ip 
						  << ":" << ntohs(_address.sin_port) << color_reset << std::endl;

				// Ajouter le client à l'instance epoll
				_ev.events = EPOLLIN | EPOLLET; // Mode de lecture avec edge-triggered
				_ev.data.fd = client_fd;

				if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_fd, &_ev) < 0) {
					std::cerr << "Erreur lors de l'ajout du client à epoll: " << strerror(errno) << std::endl;
					close(client_fd); // Fermer la connexion du client en cas d'erreur
					continue;
				}
				//Creation d'un nouveau Client et ajout au vector de client
				_clients.push_back(new Client(client_fd, client_ip, _pwd));

			} else { // Si c'est un message provenant d'un client existant
				memset(_buffer, 0, BUFFER_SIZE); // Réinitialiser le tampon de réception
				ssize_t bytes_received = recv(_events[i].data.fd, _buffer, BUFFER_SIZE - 1, 0);
				if (bytes_received <= 0) {
					if (bytes_received == 0)
						std::cout << color_red << "Deconnexion client : " <<  _events[i].data.fd << color_reset << std::endl; // Si le client s'est déconnecté // Si le client s'est déconnecté
					else {
						std::cerr << "Erreur de lecture du socket client: " << _events[i].data.fd << std::endl;
					}
					if (getClient(_events[i].data.fd).get_socket_client() == _events[i].data.fd)
					{
						epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, _events[i].data.fd, 0); // Retirer le client de epoll
						checkChannel(_events[i].data.fd);
						erase_client(_clients, _events[i].data.fd);			//
					}
				} else {
					display_message(_events[i].data.fd, bytes_received); // Afficher le message reçu
					handleIncomingMessages(_buffer, _events[i].data.fd);
				}
			}
		}
	}
}

void Server::exit_clean()
{
    send_messages(_clients, "FERMETURE DU SERVEUR\r\n");
    for (int i = _clients.size() - 1; i >= 0; --i)
    {
        int client_fd = _clients[i]->get_socket_client();
        // Supprimer le client d'epoll et vérifier si cela réussit
        if (epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, client_fd, 0) == -1)
            std::cerr << "Erreur lors de la suppression du client de l'epoll" << std::endl;
        // Fermer la socket client
		close(client_fd);
		delete _clients[i];
		_clients.pop_back();
    }
	_clients.clear();
    // Suppression du serveur d'epoll et fermeture des descripteurs de fichier
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, _server_fd, 0) == -1)
        std::cerr << "Erreur lors de la suppression du serveur de l'epoll" << std::endl;
    if (close(_server_fd) == -1)
        std::cerr << "Erreur lors de la fermeture de la socket serveur" << std::endl;
    if (close(_epoll_fd) == -1)
        std::cerr << "Erreur lors de la fermeture de l'epoll_fd" << std::endl;
    std::cout << "FERMETURE DU SERVEUR\r\n";
}

std::string Server::getChannelnamebyClient(const ParsedMessage& msg){
	std::string ret = "";
	int fd_cli = -1;
	for (size_t i = 0; i < _clients.size(); i++){
		if (msg.params[0] == _clients[i]->get_nickname())
			fd_cli = _clients[i]->get_socket_client();
	}
	for (size_t i = 0; i < _channels.size(); i++)
	{
		if (_channels[i].isClientInChannel(fd_cli)){
			if (ret != "")
				ret += "," + _channels[i].getName();
			else
				ret += _channels[i].getName();
		}
	}
	return ret;
}

Client& Server::getClient(int fd){
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i]->get_socket_client() == fd)
			return *_clients[i];
	}
	return *_clients[0];
}

bool Server::clientExist(int fd){
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i]->get_socket_client() == fd)
			return true;
	}
	return false;
}

std::string Server::get_datetime(std::time_t to_print) {
    struct std::tm* local_time = std::localtime(&to_print);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%a %d %b %Y at %H:%M:%S %Z", local_time);
    return buffer;
}

Channel* Server::findChannel(const std::string& channel_name) {
    for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
        if (it->getName() == channel_name) {
            return &(*it);
        }
    }
    return NULL;
}

// Recherche d'un client par son nickname
Client* Server::findClient(const std::string& nickname) {
    for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if ((*it)->get_nickname() == nickname) {
            return (*it);
        }
    }
    return NULL;
}

// Gestion des erreurs
const char* Server::ErrorSocketCreation::what() const throw() {
	return ("Erreur de création de socket : ");
}

const char* Server::ErrorSocketLink::what() const throw() {
	return ("Erreur de liaison de la socket : ");
}

const char* Server::ErrorSocketListen::what() const throw() {
	return ("Erreur de d'écoute de la socket : ");
}

const char* Server::ErrorEpollCreate::what() const throw() {
	return ("Erreur de création d'epoll : ");
}

const char* Server::ErrorEpollLinkToServ::what() const throw() {
	return ("Erreur lors de l'ajout du socket serveur à epoll : ");
}

const char* Server::ErrorEpollWait::what() const throw() {
	return ("Erreur lors de l'attente d'epoll : ");
}

const char* Server::ErrorSocketConnexion::what() const throw() {
	return ("Erreur lors de l'acceptation de la connexion : ");
}

const char* Server::ErrorSocketRead::what() const throw() {
	return ("Erreur de lecture du socket client : ");
}

const char* Server::ErrorSocketOption::what() const throw() {
	return ("Erreur lors de la tentative de configuration");
}

Client* Server::findClientByFd(int fd) {
    for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if ((*it)->get_socket_client() == fd) {
            return (*it);
        }
    }
    return NULL;
}