#include "../includes/Server.hpp"
#include "../includes/Parsing.hpp"

#include <sstream>

std::string	get_param(std::string &str, std::string ids, std::string stop)
{
	int			start = 0;
	int			size = 0;
	std::string	param;

	for (int i = 0; str[i]; i++)
	{
		if (ids.find(str[i]) != ids.npos)
		{
			start = i;
			while (str[i + size] && stop.find(str[i + size]) == stop.npos)
				size++;
			break;
		}
	}
	if (size > 0)
		param = str.substr(start, size);
	if (param.find("\r") != std::string::npos)
			param.erase(param.find("\r"));
	return (param);
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
	std::string	stop = " #&:+-";
	return (str[index] == ' ' && stop.find(str[index + 1]) == stop.npos);
}

std::string	get_additional_param(const std::string &str)
{
	int			start = 0;
	int			size = 0;
	std::string	stop = " #&:+-";
	std::string	target;

	start = find(str, is_valid_token);
	if (start < 0)
		return (target);
	start++;
	while (str[start + size] && stop.find(str[start + size]) == stop.npos)
			size++;
	if (size)
		target = str.substr(start, size);
	if (target.find("\r") != std::string::npos)
		target.erase(target.find("\r"));
	return (target);
}

std::string	get_flag(std::string &str)
{
	int			start = 0;
	int			size = 0;
	std::string	stop = " #&:";
	std::string	flag;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && stop.find(str[i + 1]) == stop.npos)
		{
			start = i + 1;
			while (str[start + size] && stop.find(str[start + size]) == stop.npos)
			{
				if ((str[start + size] == '+' || str[start + size] == '-') && size != 0)
					break;
				size++;
			}
			break;
		}
	}
	if (size)
		flag = str.substr(start, size);
	if (flag.find("\r") != std::string::npos)
		flag.erase(flag.find("\r"));
	return (flag);
}

std::string	itostring(int i)
{
	std::stringstream	ss;
    ss << i;
	std::string			res = ss.str();
	return (res);
}
