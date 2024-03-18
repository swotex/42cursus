#include "../includes/Server.hpp"
#include "../includes/CmdResponse.hpp"

static void	passwordCheck(std::string cmd, std::string password, Client *user)
{
	size_t pos = 0;

	if (cmd.find("PASS") != std::string::npos)
		pos = cmd.find("PASS") + 4;

	while (cmd[pos] == ' ' || cmd[pos] == '\r')
		pos++;
	if (cmd[pos] == 0)
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "PASS", *user);
	else if (user->getRegistered() == false)
	{
		if (cmd.substr(pos) == password || cmd.substr(pos) == password + '\r')
			user->setPassIsOk(true);
		else
		{
			CmdResponse::sendErrorMsg(ERR_PASSWDMISMATCH, "PASS", *user);
			user->setPassIsOk(false);
		}
	}
	else
		CmdResponse::sendErrorMsg(ERR_ALREADYREGISTRED, "PASS", *user);
}

static void	userCheck(std::string cmd, Client *user)
{
	size_t pos = 0;

	if (cmd.find("USER") != std::string::npos)
		pos = cmd.find("USER") + 4;

	while (cmd[pos] == ' ' || cmd[pos] == '\r')
		pos++;

	if (cmd[pos] == 0)
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "USER", *user);
	else if (user->getPassIsOk() == false)
		CmdResponse::sendErrorMsg(ERR_PASSWDMISMATCH, "USER", *user);
	else if (user->getRegistered() == true)
		CmdResponse::sendErrorMsg(ERR_ALREADYREGISTRED, "USER", *user);
	else
	{
		user->setUsername(cmd.substr(pos, cmd.find(" ", pos) - pos));
		if (user->getNickname().empty() == false)
			user->setRegistered(true);
	}
}

static int find(std::string str, bool (*predicate)(std::string, int))
{
	for (size_t i = 0; i < str.size(); i++)
		if (predicate(str, i))
			return (i);
	return (-1);
}

static bool	is_valid_token(std::string str, int index)
{
	std::string	stop = "#&:+-";
	return (stop.find(str[index]) != stop.npos);
}

static void	nickCheck(std::string cmd, Client *user, std::vector<Client> &clients)
{
	size_t pos = 0;

	if (cmd.find("NICK") != std::string::npos)
		pos = cmd.find("NICK") + 4;

	while (cmd[pos] == ' ' || cmd[pos] == '\r')
		pos++;
	if (cmd[pos] == 0)
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "NICK", *user);
	else if (user->getPassIsOk() == false)
		CmdResponse::sendErrorMsg(ERR_PASSWDMISMATCH, "NICK", *user);
	else
	{
		std::string tmp(cmd.substr(pos, cmd.find(" ", pos) - pos));
		if (tmp.find("\r") != std::string::npos)
			tmp.erase(tmp.find("\r"));
		if (!isalpha(tmp[0]) || find(tmp, is_valid_token) >= 0)
		{
			if (user->getNickname().empty())
				CmdResponse::sendErrorMsg(ERR_ERRONEUSNICKNAME, tmp, *user);
			else
				CmdResponse::sendErrorMsg(ERR_ERRONEUSNICKNAME, user->getNickname() + " " + tmp, *user);
			return;
		}
		for (size_t i = 0; i < clients.size(); i++)
		{
			if (clients[i].getNickname() == tmp)
			{
				CmdResponse::sendErrorMsg(ERR_NICKNAMEINUSE, tmp, *user);
				return;
			}
		}

		std::string rplMessage;
		if (user->getNickname().empty() == false)
			rplMessage = ":" + user->getNickname() + " NICK :" + tmp + "\r\n";
		else
			rplMessage = ": 001 " + tmp + " :Welcome on this IRC" + "\r\n";
		user->setNickname(tmp);
		send(user->getSocket(), rplMessage.c_str(), rplMessage.length(), 0);

		if (user->getUsername().empty() == false)
			user->setRegistered(true);
	}
}

void	uConnexion(std::string cmd, Server &server, Client *user, int flag)
{
	if (flag == PASS)
		passwordCheck(cmd, server.getPassword(), user);
	else if (flag == USER)
		userCheck(cmd, user);
	else if (flag == NICK)
		nickCheck(cmd, user, server.getClients());
}
