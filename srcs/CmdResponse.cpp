#include "../includes/CmdResponse.hpp"
#include <map>
#include <sstream>

void	CmdResponse::sendErrorMsg(e_err code, std::string cmd, Client &client)
{
	static std::pair<e_err, std::string>	err_map_data[] = {
		std::make_pair(ERR_NOSUCHNICK, 		": [CODE] :[CMD] :No such nick\r\n"),
		std::make_pair(ERR_NOSUCHCHANNEL, 	": [CODE] :[CMD] :No such channel\r\n"),
		std::make_pair(ERR_NORECIPIENT,		": [CODE] :No recipient given ([CMD])\r\n"),
		std::make_pair(ERR_NOTEXTTOSEND,	": [CODE] :[CMD] :No text to send\r\n"),
		std::make_pair(ERR_ERRONEUSNICKNAME,": [CODE] [CMD] :Erroneus nickname\r\n"),
		std::make_pair(ERR_NICKNAMEINUSE, 	": [CODE] :[CMD] :Nickname is already in use\r\n"),
		std::make_pair(ERR_USERNOTINCHANNEL,": [CODE] :[CMD] :They aren't on that channel\r\n"),
		std::make_pair(ERR_NOTONCHANNEL,	": [CODE] :[CMD] :You're not on that channel\r\n"),
		std::make_pair(ERR_USERONCHANNEL,	": [CODE] [CMD] :is already on channel\r\n"),
		std::make_pair(ERR_NOTREGISTERED,	": [CODE] :[CMD] :You have not registered\r\n"),
		std::make_pair(ERR_NEEDMOREPARAMS,	": [CODE] :[CMD] :Not enough parameters\r\n"),
		std::make_pair(ERR_ALREADYREGISTRED,": [CODE] :[CMD] :You may not reregister\r\n"),
		std::make_pair(ERR_PASSWDMISMATCH,	": [CODE] :[CMD] :Password incorrect or missing\r\n"),
		std::make_pair(ERR_KEYSET,			": [CODE] [CMD] :Channel key already set\r\n"),
		std::make_pair(ERR_CHANNELISFULL,	": [CODE] :[CMD] :Cannot join channel (channel is full)\r\n"),
		std::make_pair(ERR_UNKNOWNMODE,		": [CODE] [CMD] :is unknown mode char to me\r\n"),
		std::make_pair(ERR_INVITEONLYCHAN,	": [CODE] :[CMD] :Cannot join channel (+i)\r\n"),
		std::make_pair(ERR_BANNEDFROMCHAN,	": [CODE] :[CMD] :Cannot join channel (+b)\r\n"),
		std::make_pair(ERR_BADCHANNELKEY,	": [CODE] :[CMD] :Cannot join channel (+k)\r\n"),
		std::make_pair(ERR_CHANOPRIVSNEEDED,": [CODE] [CMD] :You're not channel operator\r\n")
	};

	static std::map<e_err, std::string>	err_map(err_map_data, err_map_data + sizeof(err_map_data) / sizeof(err_map_data[0]));

	std::string 		finalMsg = err_map[code];
	std::ostringstream	ss;

	ss << code;
	size_t	code_pattern_index = finalMsg.find("[CODE]");
	if (code_pattern_index != finalMsg.npos)
		finalMsg = finalMsg.substr(0, code_pattern_index) + ss.str() + finalMsg.substr(code_pattern_index + std::strlen("[CODE]"));

	size_t	cmd_pattern_index = finalMsg.find("[CMD]");
	if (cmd_pattern_index != finalMsg.npos)
		finalMsg = finalMsg.substr(0, cmd_pattern_index) + cmd + finalMsg.substr(cmd_pattern_index + std::strlen("[CMD]"));

	send(client.getSocket(), finalMsg.c_str(), finalMsg.length(), 0);
}

void	CmdResponse::sendReplyMsg(e_rpl code, std::string nickname, std::string name, std::string str, Client &client)
{
	std::string finalMsg;

	switch (code)
	{
		case RPL_CHANNELMODEIS:
			finalMsg.append(": 324 " + nickname + " " + name + " :" + str + "\r\n");
			break;
		case RPL_NOTOPIC:
			finalMsg.append(": 331 " + nickname + " " + name +" :No topic is set\r\n");
			break;
		case RPL_TOPIC:
			finalMsg.append(": 332 " + nickname + " " + name + " :" + str + "\r\n");
			break;
		case RPL_NAMREPLY:
			finalMsg.append(": 353 " + nickname + " = " + name + " :" + str + "\r\n");
			break;
		case RPL_ENDOFNAMES:
			finalMsg.append(": 366 " + nickname + " " + name + " :End of /NAMES list\r\n");
			break;
		default:
			break;
	}
	send(client.getSocket(), finalMsg.c_str(), finalMsg.length(), 0);
}
