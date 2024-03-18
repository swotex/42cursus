#include "../includes/Server.hpp"
#include "../includes/CmdResponse.hpp"
#include "../includes/Parsing.hpp"
#include <map>

Server::Server(std::string port, std::string password)
{
	_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (_socket == -1)
		throw(ServerSocketException());

	int	opt = 1;
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
		throw(SocketOptException());

	sockaddr_in serverAddress;
	std::memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(std::atoi(port.c_str()));

	if (bind(_socket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1)
	{
		close(_socket);
		throw(ServerBindingException());
	}

	if (listen(_socket, SOMAXCONN) == -1)
	{
		close(_socket);
		throw(ServerListenException());
	}

	_password = password;
}

Server::~Server(void)
{
	close(_socket);
}

int		Server::getSocket(void)
{
	return(_socket);
}

std::string	Server::getPassword(void)
{
	return(_password);
}

std::vector<Client> &Server::getClients(void)
{
	return (clients);
}

Client	*Server::findClient(std::string nickname)
{
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->getNickname() == nickname)
			return (&(*it));
	}
	return (NULL);
}

Channel	*Server::findChannel(std::string name)
{
	for (std::vector<Channel>::iterator it = channels.begin(); it != channels.end(); it++)
	{
		if (it->getName() == name)
			return (&(*it));
	}
	return (NULL);
}

void	Server::removeClient(Client &client)
{
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->getSocket() == client.getSocket())
		{
			close(it->getSocket());
			clients.erase(it);
			break;
		}
	}
}

void	Server::createChannel(Client &creator, std::string name)
{
	channels.push_back(Channel(creator, name));
	creator.addChannel(channels.back());
	std::string	joinMsg = ":" + creator.getNickname() + " JOIN " + channels.back().getName() + "\r\n";
	send(creator.getSocket(), joinMsg.c_str(), joinMsg.length(), 0);

	channels.back().sendNames(creator);

	if (channels.back().getTopic().empty())
		CmdResponse::sendReplyMsg(RPL_NOTOPIC, creator.getNickname(), channels.back().getName(), "", creator);
	else
		CmdResponse::sendReplyMsg(RPL_TOPIC, creator.getNickname(), channels.back().getName(), channels.back().getTopic(), creator);
}

e_cmd	get_cmd_id(std::string cmd)
{
	std::string	tmp;
	std::string	cmdsName[] = {"JOIN", "PASS", "USER", "NICK", "KICK", "INVITE", "TOPIC", "MODE", "PRIVMSG", "QUIT", "PART"};
	e_cmd		flagName[] = {JOIN, PASS, USER, NICK, KICK, INVITE, TOPIC, MODE, PRIVMSG, QUIT, PART};

	tmp.append(cmd.substr(0, cmd.find(" ")));
	if (tmp.find("\r") != std::string::npos)
		tmp.erase(tmp.find("\r"));

	for (size_t i = 0; i < 11; i++)
	{
		if (tmp == cmdsName[i])
			return (flagName[i]);
	}
	return (UNKNOWN);
}

std::vector<std::string> split(const std::string line, char separator)
{
	std::vector<std::string>	result;
	size_t						pos = 0;

	while (line.find(separator, pos) != std::string::npos)
	{
		result.push_back(line.substr(pos, line.find(separator, pos) - pos));
		pos = line.find(separator, pos);
		pos++;
	}
	result.push_back(line.substr(pos));
	return (result);
}

void	sendMessage(Client *user, char *line, std::vector<Client> *clients)
{
	std::string str = user->getNickname() + ": " + line;
	for (std::vector<Client>::iterator sendIt = clients->begin(); sendIt != clients->end(); sendIt++)
	{
		if (&(*sendIt) != user)
			send(sendIt->getSocket(), str.c_str(), str.length(), 0);
	}
}

void	privmsg(Client &requester, std::string cmd, Server &server)
{
	Client	*target;
	Channel	*channel;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	target_name;
	std::string	msg;

	if (cmd.find(":") != cmd.npos)
		target_name = get_additional_param(cmd.substr(0, cmd.find(":")));
	else
		target_name = get_additional_param(cmd);
	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (cmd.find(":") != cmd.npos)
		msg = cmd.substr(cmd.find(":") + 1);
	if (target_name.empty() && channel_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NORECIPIENT, cmd, requester);
		return;
	}
	if (msg.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NOTEXTTOSEND, "", requester);
		return;
	}
	if (!target_name.empty())
	{
		target = server.findClient(target_name);
		if (!target)
		{
			CmdResponse::sendErrorMsg(ERR_NOSUCHNICK, target_name, requester);
			return;
		}
	}
	else
	{
		channel = server.findChannel(channel_name);
		if (!channel)
		{
			CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
			return;
		}
		if (!channel->isInChannel(requester))
		{
			CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, channel_name, requester);
			return;
		}
	}
	std::string	to_send;
	if (!target_name.empty())
	{
		to_send = ":" + requester.getNickname() + " PRIVMSG " + target_name + " :" + msg + "\r\n";
		send(target->getSocket(), to_send.c_str(), to_send.length(), 0);
	}
	else
	{
		to_send = ":" + requester.getNickname() + " PRIVMSG " + channel_name + " :" + msg + "\r\n";
		channel->sendMsg(requester, to_send);
	}
}

void	quit(Client &requester, std::string params, Server &server)
{
	std::string reason;
	if (params.find(":") != params.npos)
		reason = params.substr(params.find(":") + 1);
	requester.quitChannels(reason);
	server.removeClient(requester);
	server.eraseEmptyChans();
}

int	launchCMD(Client *user, std::string line, Server &server)
{
	std::vector<std::string>	cmds = split(line.c_str(), '\n');
	e_cmd						cmd_id = UNKNOWN;
	static std::pair<e_cmd ,void(*)(Client&, std::string, Server&)>	funcs[] = {
		std::make_pair(JOIN, join),
		std::make_pair(KICK, kick),
		std::make_pair(INVITE, invite),
		std::make_pair(TOPIC, topic),
		std::make_pair(MODE, mode),
		std::make_pair(PRIVMSG, privmsg),
		std::make_pair(PART, part),
		std::make_pair(QUIT, quit)
	};

	static std::map<e_cmd, void(*)(Client&, std::string, Server&)>	map(funcs, funcs + sizeof(funcs) / sizeof(funcs[0]));

	for (size_t i = 0; cmd_id != QUIT && i < cmds.size() - 1; i++)
	{
		if (cmds[i] == "CAP LS 302\r")
			continue;
		cmd_id = get_cmd_id(cmds[i]);
		if (cmd_id == PASS || cmd_id == NICK || cmd_id == USER)
		{
			uConnexion(cmds[i], server, user, cmd_id);
			continue;
		}
		std::string	params;
		if (cmds[i].find(" ") != std::string::npos)
			params = cmds[i].substr(cmds[i].find(" "));
		if (cmd_id != UNKNOWN)
			map[cmd_id](*user, params, server);
	}
	if (cmd_id == QUIT)
		return (QUIT);
	return (0);
}

void	Server::eraseEmptyChans()
{
	for (std::vector<Channel>::iterator it = channels.begin(); it != channels.end();)
	{
		if (it->getNbUser() == 0)
			it = channels.erase(it);
		else
			it++;
	}
}

void	Server::clienthandler()
{
	while (true)
	{
		fd_set readSet;
		FD_ZERO(&readSet);
		FD_SET(_socket, &readSet);
		FD_SET(0, &readSet);

		int maxSocket = _socket;

		for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
		{
			const int& clientSocket = it->getSocket();
			FD_SET(clientSocket, &readSet);
			if (clientSocket > maxSocket)
				maxSocket = clientSocket;
		}

		if (select(maxSocket + 2, &readSet, NULL, NULL, NULL) == -1)
		{
			perror("select");
			if (g_stop)
				break;
		}

		if (FD_ISSET(_socket, &readSet))
		{
			try
			{
				clients.push_back(Client(_socket));
				FD_CLR(clients.back().getSocket(), &readSet);
			}
			catch(const int& e)
			{
			}
		}

		if (FD_ISSET(0, &readSet))
		{
			std::string	stdin;
			std::getline(std::cin, stdin);

			if (stdin == "exit" || stdin == "quit")
				return;
		}

		for (std::vector<Client>::iterator it = clients.begin(); it != clients.end();)
		{
			if (FD_ISSET(it->getSocket(), &readSet))
			{
				char buf[1024];
				std::memset(buf, 0, sizeof(buf));
				ssize_t bytesRead = recv(it->getSocket(), buf, sizeof(buf), 0);

				if (bytesRead <= 0)
				{
					std::cout << "client(" << it->getSocket() << ") is disconnected" << std::endl;
					it->quitChannels("Leaving");
					close(it->getSocket());
					it = clients.erase(it);
					eraseEmptyChans();
				}
				else
				{
					it->addToBuffer(buf);
					if (it->getBuffer().find("\n") != std::string::npos)
					{
						std::cout << "client(" << it->getSocket() << ") : " << buf;
						if (launchCMD(&(*it), it->getBuffer(), *this) == QUIT)
						{
							if (clients.size())
								it = clients.begin();
							else
								break;
						}
						else
							it->clearBuffer();
					}
					else
						std::cout << "client(" << it->getSocket() << ") : " << buf << " (partial cmd)" << std::endl;
					it++;
				}
			}
			else
				it++;
		}
	}
}
