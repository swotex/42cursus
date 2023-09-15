/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:26:48 by njegat            #+#    #+#             */
/*   Updated: 2023/08/26 10:38:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Nameless"), _grade(75), _execute(75)
{
	_isSigned = false;
}

AForm::AForm(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute)
{
	if (grade < 1 || execute < 1)
		throw GradeTooHighException();
	if (grade > 150 || execute > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _grade(cpy._grade), _execute(cpy._execute)
{
	_isSigned = cpy._isSigned;
}


AForm::~AForm(){}

std::string AForm::getName()
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_isSigned);
}

int AForm::getGrade() const
{
	return (_grade);
}

int AForm::getExecute()
{
	return (_execute);
}

std::string AForm::getName() const
{
	return (_name);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, AForm &src)
{
	os << "Form " << src.getName() << " require grade " << src.getGrade() << " to sign, and ";
	os << src.getExecute() << " to execute and the form is ";
	if (src.getSigned() == true)
		os << "already signed." << std::endl;
	else
		os << "not signed." << std::endl;
	return (os);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}
