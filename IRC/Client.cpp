#include "Client.hpp"

Client::Client(int socket, std::string _addr, std::string mdp){
	_socket_client = socket;
	_address = _addr;
	_logged = false;
	_passed = false;
	if (mdp.empty())
		_passed = true;
	_nicked = false;
	_named = false;
}

Client::~Client(){
}

std::string Client::get_username(){
	return _username;
}

int Client::get_socket_client(){
	return _socket_client;
}

std::string Client::get_nickmask(){
	std::string s = _nickmask;
	if (s.empty())
		s = _address;
	return s;
}

std::string Client::get_nickname(){
	std::string s = _nickname;
	return s;
}

std::string Client::get_hostname(){
	return _hostname;
}

std::string Client::get_realname(){
	return _realname;
}

std::string Client::get_buffer(){
	return _buffer;
}

bool Client::get_nicked(){
	return _nicked;
}

bool Client::get_named(){
	return _named;
}

void Client::set_named(){
	_named = true;
}

void Client::set_nicked(){
	_nicked = true;
}

void Client::set_buffer(std::string toadd){
	_buffer += toadd;
}

void Client::reset_buffer(){
	_buffer = "";
}

void Client::update_nickmask(){
	std::string user = _username;
	std::string nick = _nickname;
	if (nick.empty())
		nick = "*";
	if (user.empty())
		user = "*";
	std::string host = _hostname;
	if (host.empty())
		host = "host";
	_nickmask = nick + "!" + user + "@"+ host;
}

void Client::set_nickname(std::string nick){
	_nickname = nick;
	update_nickmask();
}
void Client::set_username(std::string username){
	_username = username;
}

void Client::set_hostname(std::string hostname){
	_hostname = hostname;
	update_nickmask();
}

void Client::set_realname(std::string name){
	_realname = name;
}

bool Client::get_logged(){
	return _logged;
}

bool Client::get_passed(){
	return _passed;
}

void Client::set_logged(){
	_logged = true;
}

void Client::set_passed(){
	_passed = true;
}