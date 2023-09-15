/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:39:00 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 13:06:21 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <regex.h>
#include <sstream>
#include <limits>
#include <typeinfo>

static int regexFind(std::string src, std::string pattern)
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

static int parseType(std::string src)
{
	int			i = 0;
	int			regBack;
	std::string	pattern[] = {
							"^[-]?[[:digit:]]+$",
							"^'[[:print:]]'",
							"^[-]?[[:print:]]$",
							"^[-]?[[:digit:]]+\\.[[:digit:]]+$",
							"^[-]?[[:digit:]]+\\.[[:digit:]]+f$"
							};

	while (i < 5)
	{
		regBack = regexFind(src, pattern[i]);
		if (regBack < 0)
			return (regBack);
		if (regBack == 1)
			return (i + 1);
		i++;
	}
	return (0);
}

static void notPrint(void)
{
	std::cout << "Char : Non displayable" << std::endl;
	std::cout << "Int : impossible" << std::endl;
	std::cout << "Float : nanf" << std::endl;
	std::cout << "Double : nan" << std::endl;
}

template <typename T>
void Convert(T in)
{
	char	c = static_cast<char>(in);
	int		i = static_cast<int>(in);
	float	f = static_cast<float>(in);
	double	d = static_cast<double>(in);
	if (isprint(c))
		std::cout << "Char : " << c << std::endl;
	else
		std::cout << "Char : Non displayable" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "Int : impossible" << std::endl;
	else
		std::cout << "Int : " << i << std::endl;
	if (typeid(in) == typeid(int) || typeid(in) == typeid(char))
		std::cout << "Float : " << f << ".0f" << std::endl;
	else
		std::cout << "Float : " << f << "f" << std::endl;
	if (typeid(in) == typeid(int) || typeid(in) == typeid(char))
		std::cout << "Double : " << d << ".0" << std::endl;
	else
		std::cout << "Double : " << d << std::endl;
}
template <typename T>
void Overflow(T in, int sign)
{
	std::cout << "Char : Non displayable" << std::endl;
	std::cout << "Int : impossible" << std::endl;
	if (typeid(in) == typeid(double) || typeid(in) == typeid(float))
	{
		if (sign == 1)
			std::cout << "Float : +inff" << std::endl;
		else
			std::cout << "Float : -inff" << std::endl;
	}
	else
		std::cout << "Float : nanf" << std::endl;
	if (typeid(in) == typeid(double))
	{
		if (sign == 1)
			std::cout << "Double : +inf" << std::endl;
		else
			std::cout << "Double : -inf" << std::endl;
	}
	else
		std::cout << "Double : nan" << std::endl;
}

void ScalarConverter::convert(std::string src)
{
	std::istringstream iss(src);
	int		iinput;
	char	cinput;
	double	dinput;
	float	finput;

	if(src.compare("+inf") == 0 || src.compare("+inff") == 0)
	{
		Overflow<double>((double)0, 1);
		return ;
	}
	else if(src.compare("-inf") == 0 || src.compare("-inff") == 0)
	{
		Overflow<double>((double)0, 0);
		return ;
	}

	switch (parseType(src))
	{
		case 1:
			if(!(iss >> iinput))
			{
				std::cout << "\e[1;33m[Warning] Overflow\e[0m" << std::endl;
				if (src[0] == '-')
					Overflow<int>(iinput, 0);
				else
					Overflow<int>(iinput, 1);
			}
			else
				Convert<int>(iinput);
			break;
		case 2:
			cinput = src[1];
			Convert<char>(cinput);
			break;
		case 3:
			if (src[0] == '-')
			{
				iinput = src[1];
				iinput *= -1;
			}
			else
				iinput = src[0];
			Convert<int>(iinput);
			break;
		case 4:
			if(!(iss >> dinput))
			{
				std::cout << "\e[1;33m[Warning] Overflow\e[0m" << std::endl;
				if (src[0] == '-')
					Overflow<double>(dinput, 0);
				else
					Overflow<double>(dinput, 1);
			}
			else
				Convert<double>(dinput);
			break;
		case 5:
			if(!(iss >> finput))
			{
				std::cout << "\e[1;33m[Warning] Overflow\e[0m" << std::endl;
				if (src[0] == '-')
					Overflow<float>(finput, 0);
				else
					Overflow<float>(finput, 1);
			}
			else
				Convert<float>(finput);
			break;
		case 0:
			notPrint();
			break;
		case -1:
			std::cerr << "Error regex" << std::endl;
			break;
		case -2:
			std::cerr << "Error matching" << std::endl;
			break;
		default:
			std::cerr << "Error Occurred" << std::endl;
			break;
	}
}
