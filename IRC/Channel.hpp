#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "header.hpp"



class Channel
{
private:
	std::string name;
	std::string topic;
	std::vector<int> clients;
	std::vector<int> invited_clients;
	std::vector<int> operators;
	int client_limit;
	bool invite_only;
	bool topic_restricted;
	std::string key;
	std::time_t creation_time;
	std::string topic_setter;
	std::string topic_mask;
    time_t topic_set_time;

public:
	Channel(const std::string &channel_name)
		: name(channel_name),
		  client_limit(0),
		  invite_only(false),
		  topic_restricted(false),
		  creation_time(std::time(0)) {}
	~Channel();

	std::string getCreationTimeFormatted() const;

	//gestion des clients
	void addClient(int client_fd);
	void removeClient(int client_fd);
	bool isClientInChannel(int client_fd) const;
	void addInvite(int client_fd);
	void removeInvite(int client_fd);
	bool isInvited(int client_fd) const;

	std::string getNamesList(std::vector<Client *>& clients);

	//gestion des modes
	void addOperator(int client_fd);
    void removeOperator(int client_fd);
    bool isOperator(int client_fd) const;
    void setInviteOnly(bool enabled);
    bool isInviteOnly() const;
    void setTopicRestricted(bool enabled);
    bool isTopicRestricted() const;
    void setKey(const std::string& new_key);
    void clearKey();
    const std::string& getKey() const;
    void setClientLimit(int limit);
    int getClientLimit() const;
    std::string getModeString() const;

	//getters
	int getNbrClients() const;
	std::vector<int> getClients() const;
	const std::string &getName() const;
	const std::string &getTopic() const;
	void setTopic(const std::string &new_topic, const std::string& setter_nick, const std::string& setter_mask);
	std::vector<int> getOperators() const;
	std::time_t getCreationTime() const;
	std::string getTopicSetter() const;
	std::string getTopicMask() const;
    time_t getTopicSetTime() const;


	static bool isValidChannelName(const std::string& channel_name);


};

#endif