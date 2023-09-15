/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 06:42:59 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 14:05:20 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &cpy)
{
	(void)cpy;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern() {}

static std::string strToLower(std::string src)
{
	std::string out(src);

	for ( int i=0; src[i]; i++ )
		out[i] = std::tolower(src[i]);
	return (out);
}

AForm *Intern::makeShrubbery(std::string name, std::string target)
{
	return (new ShrubberyCreationForm(name, target));
}

AForm *Intern::makeRobotomy(std::string name, std::string target)
{
	return (new RobotomyRequestForm(name, target));
}

AForm *Intern::makePresidential(std::string name, std::string target)
{
	return (new PresidentialPardonForm(name, target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string tmpLower = strToLower(name);
	std::string inputCmp[] = {"shrubbery", "robotomy", "presidential"};
	AForm *(Intern::*forms[])(std::string, std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	for ( int i=0; i < 3; i++ )
	{
		if (tmpLower.find(inputCmp[i]) != std::string::npos)
		{
			std::cout << "Intern creates " << inputCmp[i] << std::endl;
			return ((this->*forms[i])(name, target));
		}
	}
	throw FormException();
	return (NULL);
}

const char *Intern::FormException::what() const throw()
{
	return ("Form not found");
}
