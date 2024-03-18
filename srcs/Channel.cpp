#include "../includes/Channel.hpp"
#include "../includes/CmdResponse.hpp"
#include "../includes/Parsing.hpp"

Channel::Channel(Client &op, std::string name)
{
	_name = name;
	_operators.push_back(op);
	_users.push_back(op);
	userLimit = 0;
	limited = false;
	inviteOnly = false;
	topicRestriction = true;
	locked = false;
	nbUser = 1;
}

Channel::~Channel(void)
{
}

std::string	Channel::getName(void)
{
	return (_name);
}

std::string	Channel::getTopic(void)
{
	return (_topic);
}

std::string	Channel::getFlags(void)
{
	std::string	flags = "+";

	if (inviteOnly)
		flags += "i";
	if (topicRestriction)
		flags += "t";
	if (locked)
		flags += "k";
	if (limited)
		flags += "l";
	if (flags == "+")
		flags = "";
	return (flags);
}

int		Channel::getNbUser(void)
{
	return (nbUser);
}

void	Channel::kick(Client &requester, Client &target, std::string reason)
{
	if (!isInChannel(requester))
	{
		CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, _name, requester);
		return;
	}
	if (!isOperator(requester))
	{
		std::string msg = requester.getNickname() + " " + _name;
		CmdResponse::sendErrorMsg(ERR_CHANOPRIVSNEEDED, msg, requester);
		return;
	}
	if (!isInChannel(target))
	{
		CmdResponse::sendErrorMsg(ERR_USERNOTINCHANNEL, std::string(target.getNickname() + " " + _name), requester);
		return;
	}
	std::string	kickMsg = ":" + requester.getNickname() + " KICK " + _name + " " + target.getNickname() + " :" + reason + "\r\n";
	sendAll(kickMsg);
	removeOP(target);
	removeUser(target);
	target.removeChannel(*this);
}

void	Channel::join(Client &requester, std::string password)
{
	if (!isPassword(password) && !isWhiteListed(requester))
	{
		CmdResponse::sendErrorMsg(ERR_BADCHANNELKEY, _name, requester);
		return;
	}
	if (isInInviteOnly() && !isWhiteListed(requester))
	{
		CmdResponse::sendErrorMsg(ERR_INVITEONLYCHAN, _name, requester);
		return;
	}
	if (isFull() && !isWhiteListed(requester))
	{
		CmdResponse::sendErrorMsg(ERR_CHANNELISFULL, _name, requester);
		return;
	}

	_users.push_back(requester);
	requester.addChannel(*this);

	std::string	joinMsg = ":" + requester.getNickname() + "!" + requester.getUsername() + " JOIN " + _name + "\r\n";
	sendAll(joinMsg);

	if (_topic.empty())
		CmdResponse::sendReplyMsg(RPL_NOTOPIC, requester.getNickname(), _name, "", requester);
	else
		CmdResponse::sendReplyMsg(RPL_TOPIC, requester.getNickname(), _name, _topic, requester);
	nbUser++;
	sendNames(requester);
	removeWhitelist(requester);
}

void	Channel::topic(Client &requester, std::string subject)
{
	if (!isInChannel(requester))
	{
		CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, _name, requester);
		return;
	}
	if (subject.empty())
	{
		if (_topic.empty())
			CmdResponse::sendReplyMsg(RPL_NOTOPIC, requester.getNickname(), _name, "", requester);
		else
			CmdResponse::sendReplyMsg(RPL_TOPIC, requester.getNickname(), _name, _topic, requester);
		return;
	}
	if (topicRestriction && !isOperator(requester))
	{
		std::string msg = requester.getNickname() + " " + _name;
		CmdResponse::sendErrorMsg(ERR_CHANOPRIVSNEEDED, msg, requester);
		return;
	}
	_topic = subject;

	std::string	topicMsg = ":" + requester.getNickname() + " TOPIC " + _name + " :" + _topic + "\r\n";
	sendAll(topicMsg);
}

void	Channel::invite(Client &requester, Client &target)
{
	if (!isInChannel(requester))
	{
		CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, _name, requester);
		return;
	}
	if (!isOperator(requester))
	{
		std::string msg = requester.getNickname() + " " + _name;
		CmdResponse::sendErrorMsg(ERR_CHANOPRIVSNEEDED, msg, requester);
		return;
	}
	if (isInChannel(target))
	{
		std::string	msg = requester.getNickname() + " " + target.getNickname() + " " + _name;
		CmdResponse::sendErrorMsg(ERR_USERONCHANNEL, msg, requester);
		return;
	}

	std::string	inviteMsg = ": 341 " + requester.getNickname() + " " + target.getNickname() + " :" + _name + "\r\n";
	send(requester.getSocket(), inviteMsg.c_str(), inviteMsg.length(), 0);

	inviteMsg = ":" + requester.getNickname() + " INVITE " + target.getNickname() + " :" + _name + "\r\n";
	send(requester.getSocket(), inviteMsg.c_str(), inviteMsg.length(), 0);
	send(target.getSocket(), inviteMsg.c_str(), inviteMsg.length(), 0);

	_whitelist.push_back(target);
}

void	Channel::plusMode(char flag, Client &requester, std::string param, Client *target)
{
	std::string	msg;
	int			limit = 0;
	switch (flag)
	{
	case 'i':
		if (inviteOnly)
			return;
		inviteOnly = true;
		msg = ":" + requester.getNickname() + " MODE " + _name + " :+i\r\n";
		sendAll(msg);
		break;
	case 't':
		if (topicRestriction)
			return;
		topicRestriction = true;
		msg = ":" + requester.getNickname() + " MODE " + _name + " :+t\r\n";
		sendAll(msg);
		break;
	case 'k':
		if (param.empty())
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " k * :Not enough parameters\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		if (locked)
			return;
		locked = true;
		_password = param;
		msg = ":" + requester.getNickname() + " MODE " + _name + " +k :" + param + "\r\n";
		sendAll(msg);
		break;
	case 'o':
		if (param.empty())
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " o * :Not enough parameters\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		if (!target)
		{
			CmdResponse::sendErrorMsg(ERR_NOSUCHNICK, param, requester);
			return;
		}
		if (!isInChannel(*target))
			return;
		if (isOperator(*target))
			return;
		_operators.push_back(*target);
		msg = ":" + requester.getNickname() + " MODE " + _name + " +o :" + target->getNickname() + "\r\n";
		sendAll(msg);
		break;
	case 'l':
		if (param.empty())
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " l * :Not enough parameters\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		limit = std::atoi(param.c_str());
		if (limit <= 0)
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " l " + param + " :Invalid limit mode parameter\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		if (limited && userLimit == limit)
			return;
		userLimit = limit;
		limited = true;
		msg = ":" + requester.getNickname() + " MODE " + _name + " +l :" + itostring(userLimit) + "\r\n";
		sendAll(msg);
		break;
	default:
		msg = requester.getNickname() + " " + flag;
		CmdResponse::sendErrorMsg(ERR_UNKNOWNMODE, msg, requester);
		break;
	}
}

void	Channel::minusMode(char flag, Client &requester, std::string param, Client *target)
{
	std::string	msg;
	switch (flag)
	{
	case 'i':
		if (!inviteOnly)
			return;
		inviteOnly = false;
		msg = ":" + requester.getNickname() + " MODE " + _name + " :-i\r\n";
		sendAll(msg);
		break;
	case 't':
		if (!topicRestriction)
			return;
		topicRestriction = false;
		msg = ":" + requester.getNickname() + " MODE " + _name + " :-t\r\n";
		sendAll(msg);
		break;
	case 'k':
		if (param.empty())
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " k * :Not enough parameters\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		if (!locked)
			return;
		if (!isPassword(param))
		{
			msg = requester.getNickname() + " " + _name;
			CmdResponse::sendErrorMsg(ERR_KEYSET, msg, requester);
			return;
		}
		locked = false;
		msg = ":" + requester.getNickname() + " MODE " + _name + " -k :" + param + "\r\n";
		sendAll(msg);
		break;
	case 'o':
		if (param.empty())
		{
			msg = ": 461 " + requester.getNickname() + " " + _name + " o * :Not enough parameters\r\n";
			send(requester.getSocket(), msg.c_str(), msg.length(), 0);
			return;
		}
		if (!target)
		{
			CmdResponse::sendErrorMsg(ERR_NOSUCHNICK, param, requester);
			return;
		}
		if (!isInChannel(*target))
			return;
		if (!isOperator(*target))
			return;
		removeOP(*target);
		msg = ":" + requester.getNickname() + " MODE " + _name + " -o :" + target->getNickname() + "\r\n";
		sendAll(msg);
		break;
	case 'l':
		if (!limited)
			return;
		limited = false;
		msg = ":" + requester.getNickname() + " MODE " + _name + " :-l\r\n";
		sendAll(msg);
		break;
	default:
		msg = requester.getNickname() + " " + flag;
		CmdResponse::sendErrorMsg(ERR_UNKNOWNMODE, msg, requester);
		break;
	}
}

void	Channel::part(Client &requester, std::string reason)
{
	if (!isInChannel(requester))
	{
		CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, _name, requester);
		return;
	}
	std::string	partMsg = ":" + requester.getNickname() + "!" + requester.getUsername() + " PART " + _name + " :\"" + reason + "\"\r\n";
	sendAll(partMsg);
	removeOP(requester);
	removeUser(requester);
	requester.removeChannel(*this);
}

bool	Channel::isOperator(Client &target)
{
	for (std::vector<Client>::iterator it = _operators.begin(); it != _operators.end(); it++)
	{
		if (target.getSocket() == it->getSocket())
			return (true);
	}
	return (false);
}

bool	Channel::isInChannel(Client &target)
{
	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (target.getSocket() == it->getSocket())
			return (true);
	}
	return (false);
}

bool	Channel::isInInviteOnly(void)
{
	return (inviteOnly);
}

bool	Channel::isFull(void)
{
	return (limited && nbUser >= userLimit);
}

bool	Channel::isPassword(std::string &password)
{
	return (!locked ? true : !_password.compare(password));
}

bool	Channel::isWhiteListed(Client &requester)
{
	for (std::vector<Client>::iterator it = _whitelist.begin(); it != _whitelist.end(); it++)
	{
		if (requester.getSocket() == it->getSocket())
			return (true);
	}
	return (false);
}

void	Channel::sendAll(std::string msg)
{
	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		send(it->getSocket(), msg.c_str(), msg.length(), 0);
	}
}

void	Channel::sendMsg(Client &sender, std::string msg)
{
	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		std::cout << "Client to send : " << it->getNickname() << std::endl;
		if (it->getSocket() != sender.getSocket())
			send(it->getSocket(), msg.c_str(), msg.length(), 0);
	}
}

void	Channel::sendAllOP(std::string msg)
{
	for (std::vector<Client>::iterator it = _operators.begin(); it != _operators.end(); it++)
	{
		send(it->getSocket(), msg.c_str(), msg.length(), 0);
	}
}

void	Channel::removeWhitelist(Client &target)
{
	for (std::vector<Client>::iterator it = _whitelist.begin(); it != _whitelist.end(); it++)
	{
		if (it->getSocket() == target.getSocket())
		{
			_whitelist.erase(it);
			break;
		}
	}
}

void	Channel::removeOP(Client &target)
{
	for (std::vector<Client>::iterator it = _operators.begin(); it != _operators.end(); it++)
	{
		if (it->getSocket() == target.getSocket())
		{
			_operators.erase(it);
			break;
		}
	}
}

void	Channel::removeUser(Client &target)
{
	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (it->getSocket() == target.getSocket())
		{
			_users.erase(it);
			nbUser--;
			break;
		}
	}
}

void	Channel::sendNames(Client &requester)
{
	std::string	names;

	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (it != _users.begin())
			names += " ";
		if (isOperator(*it))
			names += "@";
		else
			names += "+";
		names += it->getNickname();
	}
	for (std::vector<Client>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		CmdResponse::sendReplyMsg(RPL_NAMREPLY, requester.getNickname(), _name, names, *it);
		CmdResponse::sendReplyMsg(RPL_ENDOFNAMES, requester.getNickname(), _name, "", *it);
	}
}
