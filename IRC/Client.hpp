#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <sys/epoll.h>
#include <cstring>
#include <fcntl.h>
#include <cerrno>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <sstream>

class Client
{
	private:
		std::string		_nickname; //nick

		std::string		_username; //user
		std::string 	_realname;
		std::string		_hostname;

		std::string		_nickmask;

		std::string		_address;

		std::string		_buffer; //ajoute pour reception message

		bool			_logged; //ajoute quand le client a passer l'etape de connexion (USER)
		bool			_passed; //ajoute pour pass
		bool			_nicked;
		bool			_named;
		int				_socket_client;
		// int			_role;
		void 			update_nickmask();

	public:
		Client(int client_fd, std::string _addr, std::string mdp);
		~Client();
		
		int 		get_socket_client();
		std::string get_nickmask();
		std::string get_nickname();
		std::string get_username();
		std::string get_buffer(); 				//ajoute pour reception message
		std::string get_hostname();				//ajoute pour whois
		std::string get_realname();
		bool		get_logged();				//ajoute pour les etapes de connexion
		bool		get_passed();				//ajoute pour pass
		bool		get_nicked();
		bool		get_named();
		void		set_nickname(std::string);
		void		set_username(std::string);
		void		set_hostname(std::string);
		void		set_realname(std::string);
		void		set_buffer(std::string); 	//ajoute pour reception message
		void		set_logged();				//ajoute pour etaoes de connexions
		void		set_passed();				//ajoute pour pass
		void		reset_buffer();				//ajoute pour reception message	
		void		set_nicked();
		void		set_named();
};

#endif