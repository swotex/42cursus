/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 06:36:21 by njegat            #+#    #+#             */
/*   Updated: 2023/08/20 07:26:07 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	_target = "No target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
{
	_target = cpy._target;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > 45)
		throw GradeTooLowException();
	std::cout << "*  drilling noises *" << std::endl;
	srand( time(NULL) );
	int nbRand = std::rand() % 2;
	if (nbRand == 1)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout <<"robotomy failed" << std::endl;
}
