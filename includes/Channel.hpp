#pragma once

#include <vector>
#include <cstdlib>

#include "Server.hpp"
#include "Client.hpp"


class Channel
{
	public:
		Channel(Client &op, std::string name);
		~Channel(void);

		std::string	getName(void);
		std::string	getTopic(void);
		std::string	getFlags(void);
		int			getNbUser(void);

		void		join(Client &requester, std::string password);
		void		kick(Client &requester, Client &target, std::string reason);
		void		invite(Client &requester, Client &target);
		void		topic(Client &requester, std::string subject);
		void		plusMode(char flag, Client &requester, std::string param, Client *target);
		void		minusMode(char flag, Client &requester, std::string param, Client *target);
		void		part(Client &requester, std::string reason);

		bool		isOperator(Client &target);
		bool		isInChannel(Client &target);
		bool		isWhiteListed(Client &requester);
		bool		isInInviteOnly(void);
		bool		isFull(void);
		bool		isPassword(std::string &password);

		void		removeUser(Client &target);
		void		removeOP(Client &target);
		void		removeWhitelist(Client &target);

		void		sendMsg(Client &sender, std::string msg);
		void		sendAll(std::string msg);
		void		sendAllOP(std::string msg);

		void		sendNames(Client &requester);

	private:
		std::vector<Client>	_operators;
		std::vector<Client>	_users;
		std::vector<Client>	_whitelist;
		std::string			_password;
		std::string			_topic;
		std::string			_name;
		int					nbUser;
		int					userLimit;
		bool				inviteOnly;
		bool				topicRestriction;
		bool				locked;
		bool				limited;
};
