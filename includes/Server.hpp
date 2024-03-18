#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <csignal>

#include "Exception.hpp"
#include "Client.hpp"
#include "Channel.hpp"


extern int	g_stop;

typedef enum e_cmd
{
	UNKNOWN = 11,
	JOIN = 12,
	PASS = 13,
	USER = 14,
	NICK = 15,
	KICK = 16,
	INVITE = 17,
	TOPIC = 18,
	MODE = 19,
	PRIVMSG = 20,
	QUIT = 21,
	PART = 22
}	t_cmd;


class Server
{
	public:
		Server(std::string port, std::string password);
		~Server(void);

		int					getSocket(void);
		std::string			getPassword(void);

		void				clienthandler();

		Client				*findClient(std::string username);
		Channel				*findChannel(std::string name);
		std::vector<Client>	&getClients(void);
		void				removeClient(Client &client);

		void				eraseEmptyChans(void);

		void				createChannel(Client &creator, std::string name);

	private:
		std::vector<Channel>	channels;
		std::vector<Client>		clients;
		std::string				_password;
		int						_socket;
};

void	uConnexion(std::string cmd, Server &server, Client *user, int flag);
void	join(Client &requester, std::string cmd, Server &server);
void	kick(Client &requester, std::string cmd, Server &server);
void	topic(Client &requester, std::string cmd, Server &server);
void	invite(Client &requester, std::string cmd, Server &server);
void	mode(Client &requester, std::string cmd, Server &server);
void	part(Client &requester, std::string cmd, Server &server);
