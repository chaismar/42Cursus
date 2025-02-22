#ifndef SERVER_HPP
#define SERVER_HPP

#include "header.hpp"
#include "Client.hpp"
#include "Channel.hpp"

struct S_mode{
	std::string target;
	std::string modestring;
    std::string new_modestring;
	Channel* target_channel;
};

class Server
{
	private:
    	int 				_server_fd, _epoll_fd;

    	struct sockaddr_in	_address;
    	socklen_t 			_addrlen;
    	struct epoll_event 	_ev, _events[MAX_EVENTS];
    	int 				_event_count;
    	char 				_buffer[BUFFER_SIZE];
		std::vector<Client *>	_clients;
		std::vector<Channel> _channels;
		std::string			_pwd;
		std::time_t			_datetime;

		void handleCommand(const ParsedMessage& msg, Client &cli); //modif structure
		void pass(const ParsedMessage &msg, std::string &pwd, Client &cli);
		void nick(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients);
		void user(const ParsedMessage& msg, Client &cli);
		void quit(const ParsedMessage& msg, Client &cli);
		void motd(const ParsedMessage& msg, Client &cli);
		void ping(const ParsedMessage& msg, Client &cli);
		void whois(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients);
		void display_message(int client_fd, ssize_t length);
		void handleIncomingMessages(const std::string& buffer, int fd);
		void exit_clean();
		void join(const ParsedMessage &msg, Client &cli);
		void part(const ParsedMessage& msg, Client& cli);
		void privmsg(const ParsedMessage& msg, Client& cli);
		void connect_msg(Client &cli);
		void topic(const ParsedMessage& msg, Client& cli);
		void invite(const ParsedMessage& msg, Client& cli);
		void kick(const ParsedMessage& msg, Client& cli);
		void mode(const ParsedMessage& msg, Client& cli);
		std::string getChannelnamebyClient(const ParsedMessage& msg);
		Client* findClientByFd(int fd);
		void checkChannel(int fd);
		int checkModeParams(const ParsedMessage &msg, Client &cli, S_mode &s);
		std::string execMode(const ParsedMessage &msg, Client &cli, S_mode &s);
	public:
		Server(std::string);
		~Server();
		std::string get_datetime(std::time_t);
		Client& getClient(int fd);
		bool clientExist(int fd);
		void loop();

		Channel* findChannel(const std::string& channel_name);
		Client* findClient(const std::string& nickname);
	
	class ErrorSocketCreation: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorSocketLink: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorSocketListen: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorEpollCreate: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorEpollLinkToServ: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorEpollWait: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorSocketConnexion: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorSocketRead: public std::exception {
		public :
		virtual const char *what() const throw();
	};
	class ErrorSocketOption: public std::exception {
		public :
		virtual const char *what() const throw();
	};
};

#endif