#include "../header.hpp"
#include "../Server.hpp"
#include "../Channel.hpp"

int check_mode(const ParsedMessage &msg, Client &cli){
	if ((msg.params.size() > 1 && msg.params[1].find('b') != std::string::npos)) {
        return 0;
	}
	
	if ((msg.params[0]) == cli.get_nickname()) {
		return 0;
	}
    if (msg.params.empty()) {
        send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("MODE"));
        return 0;
    }
	return (1);
}

std::string Server::execMode(const ParsedMessage &msg, Client &cli, S_mode &s){
	bool i = false;
	bool t = false;
	bool k = false;
	bool o = false;
	bool l = false;
	bool sign = true;
	std::vector<std::string> mode_arguments(msg.params.begin() + 2, msg.params.end());
    std::vector<std::string>::iterator arg_it = mode_arguments.begin();
	std::string infoModeAdd = "+";
	std::string infoModeDel = "-";
	std::string infoModeEnd = "";
	for (size_t j = 0; j < s.modestring.size(); j++)
	{
		if (s.modestring[j] == '+') //si c'est +
			sign = true;
		else if (s.modestring[j] == '-') //si c'est -
			sign = false;
		else if (s.modestring[j] == 'i' && i == false) //si c'est i
		{
			s.target_channel->setInviteOnly(sign);
			i = true;
			if (sign)
				infoModeAdd += "i";
			else
				infoModeDel += "i";

		}
		else if (s.modestring[j] == 't' && t == false){ //si c'est t
			s.target_channel->setTopicRestricted(sign);
			t = true;
			if (sign)
				infoModeAdd += "t";
			else
				infoModeDel += "t";
		}
		else if (s.modestring[j] == 'k' && k == false) //si c'est k
		{
			if (sign == true && arg_it != mode_arguments.end()){
				s.target_channel->setKey(*arg_it);
				infoModeAdd += "k";
				infoModeEnd += " " + *arg_it;
				arg_it++;
			}
			if (sign == false){
				s.target_channel->clearKey();
				infoModeDel += "k";
			}
			k = true;
		}
		else if (s.modestring[j] == 'o') //si c'est o
		{
			if (arg_it != mode_arguments.end()){
				Client * target_client = findClient(*arg_it);
            	if (!target_client)
					send_messages(cli.get_socket_client(), ERR_NOSUCHNICK(arg_it->c_str()));
				else if (!s.target_channel->isClientInChannel(target_client->get_socket_client()))
                    send_messages(cli.get_socket_client(), ERR_USERNOTINCHANNEL(cli.get_nickname(), s.target));
				else if(sign == true){
					s.target_channel->addOperator(target_client->get_socket_client());
					infoModeAdd += "o";
					infoModeEnd += " " + target_client->get_nickname();
				}
				else{
					s.target_channel->removeOperator(target_client->get_socket_client());
					infoModeDel += "o";
					infoModeEnd += " " + target_client->get_nickname();
				}
				arg_it++;
			}
			o = true;
		}
		else if (s.modestring[j] == 'l' && l == false){ //si c'est l
			if (sign == true && arg_it != mode_arguments.end()) {
				if (isNumeric(*arg_it)){
				s.target_channel->setClientLimit(std::atoi(arg_it->c_str()));
				infoModeAdd += "l";
				infoModeEnd += " " + *arg_it;
				arg_it++;
				}
				else
					arg_it++;
			}

			if (sign == false){
				s.target_channel->setClientLimit(0);
				infoModeDel += "l";
			}
			l = true;
		}
		else {
			if (o) {
				send_messages(cli.get_socket_client(), ERR_NEEDMOREPARAMS("MODE"));
				break;
			}
			else
				send_messages(cli.get_socket_client(), "unknown mode character " + std::string(1,s.modestring[j]) + "\r\n");
		}
	}
	if (infoModeAdd.size() == 1 && infoModeDel.size() == 1)
		return "";
	if (infoModeAdd.size() == 1)
		return infoModeDel;
	if (infoModeDel.size() == 1)
		return infoModeAdd + infoModeEnd;
	return infoModeAdd + infoModeDel + infoModeEnd;
}

int Server::checkModeParams(const ParsedMessage &msg, Client &cli, S_mode &s)
{
	s.target = msg.params[0];
	s.target_channel = findChannel(s.target);
	if (!s.target_channel) {
        send_messages(cli.get_socket_client(), ERR_NOSUCHCHANNEL(cli.get_nickname(), s.target));
        return 0;
    }
	s.modestring = msg.params.size() > 1 ? msg.params[1] : "";
	if (s.modestring.empty() || (s.modestring[0] != '+' && s.modestring[0] != '-')) {
        send_messages(cli.get_socket_client(), RPL_CHANNELMODEIS(cli.get_nickname(), s.target, s.target_channel->getModeString()));
        return 0;
    }
	if (!s.target_channel->isOperator(cli.get_socket_client())) {
        send_messages(cli.get_socket_client(), ERR_CHANOPRIVSNEEDED(cli.get_nickname(), s.target));
        return 0;
    }
	return 1;
}

void Server::mode(const ParsedMessage& msg, Client& cli) {
	S_mode s;
	if (check_mode(msg, cli)){
		if (checkModeParams(msg, cli, s)){
			std::string str = execMode(msg, cli, s);
			if (!str.empty())
				send_messages(s.target_channel->getClients(), RPL_MODIFMODECHAN(cli.get_nickmask(), s.target, str));
		}
	}
}