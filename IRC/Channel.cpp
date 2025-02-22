#include "Channel.hpp"
#include <algorithm>

void Channel::addClient(int client_fd) {
	if (!isClientInChannel(client_fd)) {
        std::cout << "client added in chan\r\n";
		clients.push_back(client_fd);
	}
}

void Channel::removeClient(int client_fd) {
    std::cout << clients.size() << std::endl;
    if (operators.size() > 0){
        operators.erase(std::remove(operators.begin(), operators.end(), client_fd), operators.end());
    }
	clients.erase(std::remove(clients.begin(), clients.end(), client_fd), clients.end());
}

bool Channel::isClientInChannel(int client_fd) const {
	return std::find(clients.begin(), clients.end(), client_fd) != clients.end();
}

std::vector<int> Channel::getClients() const {
	return clients;
}

const std::string &Channel::getName() const {
	return name;
}

Channel::~Channel()
{
}

bool Channel::isValidChannelName(const std::string& channel_name) {
    if (channel_name.empty() || channel_name[0] != '#') {
        return false;
    }
    if (channel_name.size() > 32) {
        return false;
    }
    for (std::string::const_iterator it = channel_name.begin(); it != channel_name.end(); ++it) {
		char c = *it;
		if (c == ' ' || c == ',' || c == ':' || std::iscntrl(c))
			return false;
    }
    return true;
}

const std::string &Channel::getTopic() const {
	return topic;
}

void Channel::setTopic(const std::string &new_topic, const std::string &setter_nick, const std::string &setter_mask) {
	topic = new_topic;
	topic_setter = setter_nick;
	topic_mask = setter_mask;
    topic_set_time = std::time(NULL);
}

std::string Channel::getTopicSetter() const {
    return topic_setter;
}

std::string Channel::getTopicMask() const {
	return topic_mask;
}

time_t Channel::getTopicSetTime() const {
    return topic_set_time;
}

void Channel::addInvite(int client_fd) {
	if (std::find(invited_clients.begin(), invited_clients.end(), client_fd) == invited_clients.end())
		invited_clients.push_back(client_fd);
}

void Channel::removeInvite(int client_fd) {
    std::vector<int>::iterator it = std::find(invited_clients.begin(), invited_clients.end(), client_fd);
    if (it != invited_clients.end()) {
        invited_clients.erase(it);
    }
}

bool Channel::isInvited(int client_fd) const {
	return std::find(invited_clients.begin(), invited_clients.end(), client_fd) != invited_clients.end();
}

void Channel::addOperator(int fd) {
    if (std::find(operators.begin(), operators.end(), fd) == operators.end()) {
        std::cout << "client added in chan as operator\r\n";
        operators.push_back(fd);
    }
}

void Channel::removeOperator(int fd) {
    operators.erase(std::remove(operators.begin(), operators.end(), fd), operators.end());
}

bool Channel::isOperator(int fd) const {
    return std::find(operators.begin(), operators.end(), fd) != operators.end();
}

std::vector<int> Channel::getOperators() const {
    return operators;
}

void Channel::setInviteOnly(bool enabled) {
    invite_only = enabled;
}

bool Channel::isInviteOnly() const {
    return invite_only;
}

void Channel::setTopicRestricted(bool enabled) {
    topic_restricted = enabled;
}

bool Channel::isTopicRestricted() const {
    return topic_restricted;
}

void Channel::setKey(const std::string& new_key) {
    key = new_key;
}

void Channel::clearKey() {
    key.clear();
}

const std::string& Channel::getKey() const {
    return key;
}

void Channel::setClientLimit(int limit) {
    client_limit = limit;
}

int Channel::getClientLimit() const {
    return client_limit;
}

std::time_t Channel::getCreationTime() const {
	return creation_time;
}

int Channel::getNbrClients() const{
    return clients.size();
}

std::string Channel::getModeString() const {
    std::string mode_string = "+";
    if (invite_only) mode_string += "i";
    if (topic_restricted) mode_string += "t";
    if (!key.empty()) mode_string += "k";
    if (client_limit > 0) mode_string += "l";
    return mode_string;
}

std::string Channel::getNamesList(std::vector<Client *>& all_clients) {
    std::string names_list;
    for (std::vector<int>::const_iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
        int fd = *it;
        // Trouver le Client correspondant au fd
        for (std::vector<Client *>::iterator cli_it = all_clients.begin(); cli_it != all_clients.end(); ++cli_it) {
            if ((*cli_it)->get_socket_client() == fd) {
                std::string prefix;
                if (isOperator(fd)) {
                    prefix = "@";
                }
                names_list += prefix + (*cli_it)->get_nickname() + " ";
                break; // On a trouvé le client, on peut sortir de la boucle interne
            }
        }
    }
    // Supprimer l'espace final
    if (!names_list.empty() && names_list[names_list.size() - 1] == ' ') {
        names_list.erase(names_list.size() - 1);
    }
    return names_list;
}

std::string Channel::getCreationTimeFormatted() const {
	struct std::tm* local_time = std::localtime(&creation_time);
	if (!local_time)
        return "Invalid Time";
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%a %d %b %Y at %H:%M:%S %Z", local_time);
	return buffer;
}