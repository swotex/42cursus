#include "../includes/Client.hpp"
#include "../includes/Channel.hpp"

Client::Client(int serverSocket)
{
	_registered = false;
	_passIsOk = false;
	sockaddr_in	address;
	socklen_t	addressLen = sizeof(address);
	_socket = accept(serverSocket, reinterpret_cast<sockaddr*>(&address), &addressLen);

	std::cout << "client(" << _socket << ") is trying to connect" << std::endl;

	if (_socket == -1)
		throw(0);
}

Client::Client(const Client &obj)
{
	*this = obj;
}

Client::~Client(void)
{
}

Client	&Client::operator=(const Client &obj)
{
	if (this == &obj)
		return (*this);
	_registered = obj._registered;
	_passIsOk = obj._passIsOk;
	_username = obj._username;
	_nickname = obj._nickname;
	_socket = obj._socket;
	return (*this);
}

int			Client::getSocket(void)
{
	return (_socket);
}

void		Client::setNickname(std::string nickname)
{
	_nickname = nickname;
}

std::string	Client::getNickname(void)
{
	return (_nickname);
}

void		Client::setUsername(std::string username)
{
	_username = username;
}

std::string	Client::getUsername(void)
{
	return (_username);
}

void	Client::setRegistered(bool state)
{
	_registered = state;
}

bool	Client::getRegistered(void)
{
	return (_registered);
}

void	Client::setPassIsOk(bool state)
{
	_passIsOk = state;
}
bool	Client::getPassIsOk(void)
{
	return (_passIsOk);
}

void	Client::addToBuffer(char *line)
{
	_input_buffer += line;
}

std::string	Client::getBuffer(void)
{
	return (_input_buffer);
}

void	Client::clearBuffer(void)
{
	_input_buffer.clear();
}

void	Client::addChannel(Channel &channel)
{
	_channels.push_back(&channel);
}

void	Client::removeChannel(Channel &channel)
{
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == channel.getName())
		{
			_channels.erase(it);
			break;
		}
	}
}

void	Client::quitChannels(std::string reason)
{
	std::string	msg = ":" + _nickname + " QUIT :" + reason + "\r\n"; 
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		(*it)->sendAll(msg);
		(*it)->removeOP(*this);
		(*it)->removeUser(*this);
		(*it)->removeWhitelist(*this);
	}
}
