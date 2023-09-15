/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:14 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 18:07:53 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <regex.h>
#include <ctime>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::string infile)
{
	if (infile.empty())
		throw NameFileException();
	_infile = infile;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : _data(cpy._data), _infile(cpy._infile) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this == &src)
		return (*this);
	_infile = src._infile;
	_data.operator=(src._data);
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static int regexLine(std::string src, std::string pattern)
{
	regex_t		preg;
	int			error;

	error = regcomp(&preg, pattern.c_str(), REG_EXTENDED);
	if (error != 0)
	{
		return (-1);
	}
	error = regexec(&preg, src.c_str(), 0, NULL, 0);
	regfree(&preg);
	if (error == 0)
	{
		return (1);
	}
	else if (error == REG_NOMATCH)
	{
		return (0);
	}
	else
	{
		return (-2);
	}
	return (0);
}

static bool is_validDay(int year, int month, int day)
{
	int days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && month == 2)
	{
		if (day > 29)
			return (false);
		else
			return (true);
	}
	else if (day > days[month - 1])
		return (false);
	else
		return (true);
}

static bool dateIsValid(std::string line)
{
	std::string date;
	int year = 0;
	int month = 0;
	int	day = 0;

	date = line.substr(0, line.find(" "));
	struct tm tm;

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);
	std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (is_validDay(year, month, day) == false)
		return (false);
	return (true);
}

static bool valueIsValid(std::string line)
{
	std::string value;
	float		fvalue;

	value = line.substr(line.find("|") + 2);
	std::istringstream iss(value);
	if (!(iss >> fvalue))
	{
		std::cerr << "Error : Float overflow" << std::endl;
		return (false);
	}
	if (fvalue < 0 || fvalue > 1000)
	{
		std::cerr << "Error : Float not between 0 and 1000" << std::endl;
		return (false);
	}
	return (true);
}

static bool lineIsValid(std::string line)
{
	std::string pattern("^[[:digit:]]{4}-[[:digit:]]{2}-[[:digit:]]{2} \\| [[:digit:]]+([.][[:digit:]]+)?$");
	
	switch (regexLine(line, pattern))
	{
		case 0:
			std::cerr << "Error : Bad infile format : " << line << std::endl;
			return (false);
			break;
		case 1:
			if (dateIsValid(line) == false)
			{
				std::cerr << "Error : Infile invalid date : " << line << std::endl;
				return (false);
			}
			return (valueIsValid(line));
					
		default:
			std::cerr << "Error : Regex fatal error" << std::endl;
			return (false);
			break;
	}
	return (true);
}

void BitcoinExchange::execute()
{
	cpyData();

	std::ifstream Ifile(_infile.c_str());
	std::string line;
	std::string key;
	float value;
	unsigned int pos = 0;

	if (Ifile.is_open() == false)
		throw OpenInfileException();
	
	while (std::getline(Ifile, line))
	{
		pos++;
		if (line.compare("date | value") == 0 && pos == 1)
			continue;
		if (line.empty() == true)
			continue;
		if (lineIsValid(line) == false)
			continue;
		key = line.substr(0, line.find(" "));
		value = std::atof(line.substr(line.find("|") + 2).c_str());
		std::map<std::string, float>::iterator save = _data.end();
		for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
		{
			if (it->first.compare(key) == 0)
			{
				save = it;
				break;
			}
			if (it->first.compare(key) > 0)
				break;
			save = it;
		}
		if (save != _data.end())
			std::cout << key << " => " << value << " * " << save->second << " = "  << value * save->second << std::endl;
		else
			std::cerr << "Error :  Out of range " << std::endl;
	}
}



static std::string manaDate(std::string line)
{
	std::string date;
	int year = 0;
	int month = 0;
	int	day = 0;

	date = line.substr(0, line.find(","));
	struct tm tm;

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::exception();
	std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (is_validDay(year, month, day) == false)
		throw std::exception();
	return (date);
}

static float getValue(std::string line)
{
	std::string value;
	float		fvalue;

	value = line.substr(line.find(",") + 1);
	std::istringstream iss(value);
	if (!(iss >> fvalue))
	{
		std::cerr << "Float overflow" << std::endl;
		throw std::exception();
	}
	return (fvalue);
}

void BitcoinExchange::cpyData()
{
	std::ifstream Dfile(DATAFILE);
	std::string line;
	std::string pattern("^[[:digit:]]{4}-[[:digit:]]{2}-[[:digit:]]{2},[[:digit:]]+([.][[:digit:]]+)?$");
	unsigned int nbline = 0;
	std::string date;
	float value;

	if (Dfile.is_open() == false)
		throw OpenDataException();
	while (std::getline(Dfile, line))
	{
		nbline++;
		if (line.empty() == true)
			continue;
		if (nbline == 1 && line.compare("date,exchange_rate") == 0)
			continue;
		switch (regexLine(line, pattern))
		{
			case 0:
				std::cerr << "Data line " << nbline << " : " << line << std::endl;
				throw ErrorDataFormat();
				break;

			case 1:
				try
				{
					date = manaDate(line);
					value = getValue(line);
					_data.insert( std::pair<std::string,float>(date, value) );
				}
				catch(const std::exception& e)
				{
					std::cerr << "Data line " << nbline << " : " << line << std::endl;
					throw ErrorDataFormat();
				}
				break;
			
			default:
				std::cerr << "Data line " << nbline << " : " << line << std::endl;
				throw FatalErrorException();
				break;
		}
	}
}

const char *BitcoinExchange::NameFileException::what() const throw()
{
	return ("Open infile fail");
}

const char *BitcoinExchange::OpenDataException::what() const throw()
{
	return ("Open data file fail");
}

const char *BitcoinExchange::FatalErrorException::what() const throw()
{
	return ("Fatal Error");
}

const char *BitcoinExchange::ErrorDataFormat::what() const throw()
{
	return ("Wrong format of data file");
}

const char *BitcoinExchange::OpenInfileException::what() const throw()
{
	return ("Open user file fail");
}
