#pragma once

#include <iostream>
#include <cstdlib>
#include "Client.hpp"

typedef enum e_err
{
	ERR_NOSUCHNICK = 401,
	ERR_NOSUCHCHANNEL = 403,
	ERR_NORECIPIENT = 411,
	ERR_NOTEXTTOSEND = 412,
	ERR_ERRONEUSNICKNAME = 432,
	ERR_NICKNAMEINUSE = 433,
	ERR_USERNOTINCHANNEL = 441,
	ERR_NOTONCHANNEL = 442,
	ERR_USERONCHANNEL = 443,
	ERR_NOTREGISTERED = 451,
	ERR_NEEDMOREPARAMS = 461,
	ERR_ALREADYREGISTRED = 462,
	ERR_PASSWDMISMATCH = 464,
	ERR_KEYSET = 467,
	ERR_CHANNELISFULL = 471,
	ERR_UNKNOWNMODE = 472,
	ERR_INVITEONLYCHAN = 473,
	ERR_BANNEDFROMCHAN = 474,
	ERR_BADCHANNELKEY = 475,
	ERR_CHANOPRIVSNEEDED = 482
}	t_err;

typedef enum e_rpl
{
	RPL_CHANNELMODEIS = 324,
	RPL_NOTOPIC = 331,
	RPL_TOPIC = 332,
	RPL_NAMREPLY = 353,
	RPL_ENDOFNAMES = 366
}	t_rpl;

namespace CmdResponse
{
	void	sendErrorMsg(e_err code, std::string cmd, Client &client);
	void	sendReplyMsg(e_rpl code, std::string nickname, std::string name, std::string str, Client &client);
};
