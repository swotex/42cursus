/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 05:38:18 by njegat            #+#    #+#             */
/*   Updated: 2023/08/20 07:24:52 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	_target = "No target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
{
	_target = cpy._target;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > 137)
		throw GradeTooLowException();
	std::string tmp(_target + "_shrubbery");
	std::ofstream outfile(tmp.c_str());
	if (outfile.is_open())
	{
		outfile << "                      v .   ._, |_  .," << std::endl;
		outfile << "           `-._\\/  .  \\ /    |/_" << std::endl;
		outfile << "               \\\\  _\\, y | \\//" << std::endl;
		outfile << "         _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
		outfile << "           `7-,--.`._||  / / ," << std::endl;
		outfile << "           /'     `-. `./ / |/_.'" << std::endl;
		outfile << "                     |    |//" << std::endl;
		outfile << "                     |_    /" << std::endl;
		outfile << "                     |-   |" << std::endl;
		outfile << "                     |   =|" << std::endl;
		outfile << "                     |    |" << std::endl;
		outfile << "--------------------/ ,  . \\--------._" << std::endl;
		outfile.close();
	}
	else
		std::cerr << "Open file error" << std::endl;
}
