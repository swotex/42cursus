#pragma once

#include "Server.hpp"

struct	Cmd_args
{
	std::string	channel_name;
	std::string	mode;
	std::string	reason;
	std::string	param;
};

std::string	get_param(std::string &str, std::string ids, std::string stop);
std::string	get_additional_param(const std::string &str);
std::string	get_flag(std::string &str);
std::string	itostring(int i);
