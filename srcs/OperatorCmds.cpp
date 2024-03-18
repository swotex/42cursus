#include "../includes/Server.hpp"
#include "../includes/CmdResponse.hpp"
#include "../includes/Parsing.hpp"

bool	channel_exists(Channel **channel, Client &requester, Server &server, std::string &channel_name)
{
	if (channel_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "JOIN", requester);
		return (false);
	}
	*channel = server.findChannel(channel_name);
	if (!*channel)
	{
		server.createChannel(requester, channel_name);
		return (false);
	}
	return (true);
}

void	join(Client &requester, std::string cmd, Server &server)
{
	Channel		*channel;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	channel_password = get_additional_param(cmd);

	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (!channel_exists(&channel, requester, server, channel_name))
		return;
	channel->join(requester, channel_password);
}

void	kick(Client &requester, std::string cmd, Server &server)
{
	Channel		*channel;
	Client		*target;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	target_name = get_additional_param(cmd);
	std::string	reason;

	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (cmd.find(":") != cmd.npos)
		reason = cmd.substr(cmd.find(":") + 1);
	if (channel_name.empty() || target_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "KICK", requester);
		return;
	}
	channel = server.findChannel(channel_name);
	target = server.findClient(target_name);
	if (!channel)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
		return;
	}
	if (!target)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHNICK, target_name, requester);
		return;
	}
	channel->kick(requester, *target, reason);
	server.eraseEmptyChans();
}

void	topic(Client &requester, std::string cmd, Server &server)
{
	Channel		*channel;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	subject;

	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (cmd.find(":") != cmd.npos)
		subject = cmd.substr(cmd.find(":") + 1);
	if (channel_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "TOPIC", requester);
		return;
	}
	channel = server.findChannel(channel_name);
	if (!channel)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
		return;
	}
	channel->topic(requester, subject);
}

void	invite(Client &requester, std::string cmd, Server &server)
{
	Channel		*channel;
	Client		*target;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	target_name = get_additional_param(cmd);

	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (channel_name.empty() || target_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "INVITE", requester);
		return;
	}
	channel = server.findChannel(channel_name);
	target = server.findClient(target_name);
	if (!channel)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
		return;
	}
	if (!target)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHNICK, target_name, requester);
		return;
	}
	channel->invite(requester, *target);
}

void	mode(Client &requester, std::string cmd, Server &server)
{
	Channel	*channel;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	flag = get_flag(cmd);

	if (!requester.getRegistered())
	{
		CmdResponse::sendErrorMsg(ERR_NOTREGISTERED, requester.getNickname(), requester);
		return;
	}
	if (channel_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "MODE", requester);
		return;
	}

	std::string	param = cmd.substr(cmd.find(flag));
	if (!flag.empty() && (flag[0] == 'l' || flag[1] == 'l'))
		param = get_flag(param);
	else
		param = get_additional_param(param);

	channel = server.findChannel(channel_name);

	if (!channel)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
		return;
	}
	if (!channel->isInChannel(requester))
	{
		CmdResponse::sendErrorMsg(ERR_NOTONCHANNEL, channel->getName(), requester);
		return;
	}
	if (flag.empty())
	{
		flag = channel->getFlags();
		CmdResponse::sendReplyMsg(RPL_CHANNELMODEIS, requester.getNickname(), channel->getName(), flag, requester);
		return;
	}
	if (!channel->isOperator(requester))
	{
		std::string msg = requester.getNickname() + " " + channel->getName();
		CmdResponse::sendErrorMsg(ERR_CHANOPRIVSNEEDED, msg, requester);
		return;
	}
	if (flag[0] == '-')
	{
		for (int i = 1; flag[i]; i++)
			channel->minusMode(flag[i], requester, param, server.findClient(param));
	}
	else
	{
		for (int i = 0; flag[i]; i++)
		{
			if (flag[i] == '+' && i == 0)
				continue;
			channel->plusMode(flag[i], requester, param, server.findClient(param));
		}
	}
}

void	part(Client &requester, std::string cmd, Server &server)
{
	Channel	*channel;
	std::string	channel_name = get_param(cmd, "#&", " ");
	std::string	reason;

	if (channel_name.empty())
	{
		CmdResponse::sendErrorMsg(ERR_NEEDMOREPARAMS, "PART", requester);
		return;
	}
	if (cmd.find(":") != cmd.npos)
		reason = cmd.substr(cmd.find(":") + 1);
	channel = server.findChannel(channel_name);

	if (!channel)
	{
		CmdResponse::sendErrorMsg(ERR_NOSUCHCHANNEL, channel_name, requester);
		return;
	}
	channel->part(requester, reason);
	server.eraseEmptyChans();
}
