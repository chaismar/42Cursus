#ifndef HEADER_HPP
#define HEADER_HPP

#include "Client.hpp"
#include "Channel.hpp"
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
#include <csignal>
#include <cstdlib>
#include <algorithm>
#include <sstream>

const std::string color_green = "\033[32m";			//Vert pour les messages du serveur
const std::string color_red = "\033[31m";			//Rouge pour les connexion / decoonnnexion
const std::string color_blue = "\033[34m";			//Bleu pour les messages recues
const std::string color_orange = "\033[38;5;214m";	//Orange pour les commandes
const std::string color_violet = "\033[35m"; 		// Magenta/Violet pour les reponses
const std::string color_reset = "\033[0m";			//Réinitialiser la couleur

#define IRCNAME "wnguyen-lmarchai.local"
#define VERSION "1.1"
#define PORT 6667
#define MAX_EVENTS 10
#define BUFFER_SIZE 1064

//Reponses connexion
#define RPL_WELCOME(nick) 										(":" + std::string(IRCNAME) + " 001 " + std::string(nick) + " :Welcome to the IRC server\r\n")
#define RPL_YOURHOST(nick)										(":" + std::string(IRCNAME) + " 002 " + std::string(nick) + " :Your host is " + std::string(IRCNAME) + " ,running version " + std::string(VERSION) + "\r\n")
#define RPL_CREATED(nick, datetime) 							(":" + std::string(IRCNAME) + " 003 " + std::string(nick) + " :This server was created " + std::string(datetime) + "\r\n")
#define ERR_NOSUCHSERVER(nick) 									(":" + std::string(IRCNAME) + " 402 " + std::string(nick) + " :No server to server communication handled\r\n")
#define ERR_NOTREGISTERED 										"451 * :You have not registered\r\n"
// Réponses USER et PASS
#define ERR_NEEDMOREPARAMS(command) 							(std::string(":") + IRCNAME + " 461 " + std::string(command) + " :Not enough parameters\r\n")
#define ERR_ALREADYREGISTERED(command) 							(std::string(":") + IRCNAME + " 462 " + std::string(command) + " :You may not reregister\r\n")
//Reponses NICK
#define ERR_NONICKNAMEGIVEN() 									(std::string(":") + IRCNAME + " 431 * :No nickname given\r\n")
#define ERR_ERRONEUSNICKNAME(nick) 								(std::string(":") + IRCNAME + " 432 * :Erroneous nickname\r\n")
#define ERR_NICKNAMEINUSE(nicktry, nick) 						(std::string(":") + IRCNAME + " 433 * "+  std::string(nick) +" :Nickname is already in use your nick is " + std::string(nick) +"\r\n")
#define RPL_NICK(nickmask, nick)								(std::string(":") + std::string(nickmask) + " NICK :" + std::string(nick) + "\r\n")
// Reponses PASS
#define ERR_PASSWDMISMATCH() 									(std::string(":") + IRCNAME + " 464 " + " : Password incorrect\r\n")
// Reponses QUIT
#define RPL_QUIT(msg)											(std::string(":") + IRCNAME + " QUIT :" + msg + "\r\n")
//MOTD
#define MOTD_START(nick) 										(":" + std::string(IRCNAME) + " 375 " + std::string(nick) + " :- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \r\n")
#define MOTD_END(nick) 											(":" + std::string(IRCNAME) + " 376 " + std::string(nick) + " :- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \r\n")
#define MOTD_1(nick)											(":" + std::string(IRCNAME) + " 372 " + std::string(nick) + " :         Welcome to the IRC Server: " + std::string(IRCNAME) + "\r\n")
#define MOTD_2(nick)											(":" + std::string(IRCNAME) + " 372 " + std::string(nick) + " :               Your gateway to the IRC community!\r\n")
//WHOIS
#define ERR_NOSUCHNICK(nick) 									(":" + std::string(IRCNAME) + " 401 " + std::string(nick) + " :No such nick\r\n")
#define RPL_WHOISUSER(nick, hisnick, username, host, realname) 	(":" + std::string(IRCNAME) + " 311 " + std::string(nick) + " " + std::string(hisnick) + " " + std::string(username) + " " + std::string(host) + " :" + std::string(realname) + "\r\n")
#define RPL_WHOISCHANNELS(nick, hisnick, channels) 				(":" + std::string(IRCNAME) + " 319 " + std::string(nick) + " " + std::string(hisnick) + " " + std::string(channels) + "\r\n")
#define RPL_WHOISSERVER(nick, hisnick)							(":" + std::string(IRCNAME) + " 312 " + std::string(nick) + " " + std::string(hisnick) + " " + std::string(IRCNAME) + ":ft_IRC42\r\n")
#define RPL_ENDOFWHOIS(nick, hisnick)							(":" + std::string(IRCNAME) + " 318 " + std::string(nick) + " " + std::string(hisnick) + ":End of WHOIS list\r\n")
//MODE
#define ERR_UMODEUNKNOWNFLAG(nick)								(":" + std::string(IRCNAME) + " 501 " + std::string(nick) + " :Unknown MODE flag\r\n")
#define RPL_CHANNELMODEIS(nick, channel, modes)					(":" + std::string(IRCNAME) + " 324 " + std::string(nick) + " " + std::string(channel) + " " + std::string(modes) + "\r\n")
#define RPL_MODIFMODECHAN(nickmask, target, modifs)				(":" + std::string(nickmask) + " MODE " + std::string(target) + " " + std::string(modifs) + "\r\n")
//INVITE
#define RPL_INVITING(nick, target_nick, channel)				(":" + std::string(IRCNAME) + " 341 " + std::string(nick) + " " + std::string(target_nick) + " " + std::string(channel) + "\r\n")

#define ERR_USERONCHANNEL(nick, channel)						(":" + std::string(IRCNAME) + " 443 " + std::string(nick) + " " + std::string(channel) + " :is already on channel\r\n")
//TOPIC
#define RPL_NOTOPIC(nick, channel)								(":" + std::string(IRCNAME) + " 331 " + std::string(nick) + " " + std::string(channel) + " :No topic is set\r\n")
#define RPL_TOPIC(nick, channel, topic)							(":" + std::string(IRCNAME) + " 332 " + std::string(nick) + " " + std::string(channel) + " :" + std::string(topic) + "\r\n")
#define RPL_TOPICWHOTIME(nick, channel, setter, time, setter_mask)	(":" + std::string(IRCNAME) + " 333 " + std::string(nick) + " " + std::string(channel) + " " + std::string(setter) + " " + std::string(setter_mask) + " " + convertToString(time) + "\r\n" )
//KICK
#define ERR_USERNOTINCHANNEL(nick, channel)						(":" + std::string(IRCNAME) + " 441 " + std::string(nick) + " " + std::string(channel) + " :They aren't on that channel\r\n")
#define ERR_CHANOPRIVSNEEDED(nick, channel)						(":" + std::string(IRCNAME) + " 482 " + std::string(nick) + " " + std::string(channel) + " :You're not channel operator\r\n")
//JOIN
#define RPL_CREATIONTIME(nick, channel, creation_time)        	(":" + std::string(IRCNAME) + " 329 " + std::string(nick) + " " + std::string(channel) + " " + convertToString(creation_time) + "\r\n")
#define ERR_BADCHANNELKEY(nick, channel)						(":" + std::string(IRCNAME) + " 475 " + std::string(nick) + " " + std::string(channel) + " :Cannot join channel (+k)\r\n")
#define ERR_CHANNELISFULL(nick, channel)						(":" + std::string(IRCNAME) + " 471 " + std::string(nick) + " " + std::string(channel) + " :Cannot join channel (+l)\r\n")
#define ERR_CANNOTSENDTOCHAN(nick, channel)						(":" + std::string(IRCNAME) + " 404 " + std::string(nick) + " " + std::string(channel) + " :Cannot send to channel\r\n")
#define ERR_INVITEONLYCHAN(nick, channel)						(":" + std::string(IRCNAME) + " 473 " + std::string(nick) + " " + std::string(channel) + " :Cannot join channel (+i)\r\n")
#define ERR_NONICKNAMEGIVEN_JOIN() 								(std::string(":") + IRCNAME + " 431 : No nickname given\r\n")
#define ERR_NEEDMOREPARAMS_JOIN(nick)							(":" + std::string(IRCNAME) + " 461 " + std::string(nick) + " :Not enough parameters\r\n")
#define ERR_NOSUCHCHANNEL(nick, channel)						(":" + std::string(IRCNAME) + " 403 " + std::string(nick) + " " + std::string(channel) + " :No such channel\r\n")
#define ERR_NOTONCHANNEL(nick, channel)							(":" + std::string(IRCNAME) + " 442 " + std::string(nick) + " " + std::string(channel) + " :You're not on that channel\r\n")
#define ERR_NORECIPIENT(nick)									(":" + std::string(IRCNAME) + " 411 " + std::string(nick) + " :No recipient given (PRIVMSG)\r\n")
#define ERR_NOTEXTTOSEND(nick)									(":" + std::string(IRCNAME) + " 412 " + std::string(nick) + " :No text to send\r\n")
#define ERR_BADCHANMASK(nick, channel)							(":" + std::string(IRCNAME) + " 476 " + std::string(nick) + " " + std::string(channel) + " :Bad Channel Mask\r\n")
#define RPL_NAMREPLY(nick, channel, names)						(":" + std::string(IRCNAME) + " 353 " + std::string(nick) + " = " + std::string(channel) + " :" + std::string(names) + "\r\n")
#define RPL_ENDOFNAMES(nick, channel)							(":" + std::string(IRCNAME) + " 366 " + std::string(nick) + " " + std::string(channel) + " :End of /NAMES list.\r\n")
//PART
#define RPL_CHANDISCONECT(nickmask)								(":" + std::string(nickmask) + " QUIT :Client Quit\r\n")
struct ParsedMessage {
	std::string prefix;
	std::string command;
	std::vector<std::string> params;
	std::string trailing;
	bool has_colon;
};

class ErrorSendMessage: public std::exception {
	public :
	virtual const char *what() const throw();
};

void printDateTime(std::time_t to_print);

void send_messages(int fd, const std::string& message);
void send_messages(std::vector<Client *>& cli, const std::string& message);
void send_messages(const std::vector<int>& fd, const std::string& message);

int check_char(char c, const std::string& str);
int check_string(const std::string& str1, const std::string& str2);

void erase_client(std::vector<Client *>& clients, int fd);

void print_motd(Client &cli);

std::string convertToString(long num);

// void nick(const ParsedMessage& msg, Client &cli, std::vector<Client *> &clients);
// void user(const ParsedMessage& msg, Client &cli);
// void pass(const ParsedMessage& msg, std::string &pwd, Client &cli);
int check_char(char c, const std::string& str);
int check_string(const std::string& str1, const std::string& str2);
int isNumeric(const std::string& str);
int check_special(const std::string &str);
void nick(const ParsedMessage& msg, Client& cli, std::vector<Client *> &clients);
void user(const ParsedMessage& msg, Client cli, std::vector<Client *> &clients);
#endif