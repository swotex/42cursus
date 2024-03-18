#pragma once

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>

class Channel;

class Client
{
	public:
		Client(int serverSocket);
		Client(const Client &obj);
		~Client(void);

		Client &operator=(const Client &obj);

		int			getSocket(void);
		void		setNickname(std::string nickname);
		std::string	getNickname(void);
		void		setUsername(std::string username);
		std::string	getUsername(void);
		void		setPassIsOk(bool state);
		bool		getPassIsOk(void);
		void		setRegistered(bool state);
		bool		getRegistered(void);
		void		addToBuffer(char *line);
		std::string	getBuffer(void);
		void		clearBuffer(void);

		void		addChannel(Channel &channel);
		void		removeChannel(Channel &channel);

		void		quitChannels(std::string reason);

	private:
		std::vector<Channel*>	_channels;
		bool					_registered;
		bool					_passIsOk;
		std::string 			_nickname; //unique
		std::string 			_username; //not unique
		int						_socket;
		std::string				_input_buffer;
};
