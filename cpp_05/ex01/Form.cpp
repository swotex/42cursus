/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:26:48 by njegat            #+#    #+#             */
/*   Updated: 2023/08/26 10:37:27 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Nameless"), _grade(75), _execute(75)
{
	_isSigned = false;
}

Form::Form(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute)
{
	if (grade < 1 || execute < 1)
		throw GradeTooHighException();
	if (grade > 150 || execute > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

Form::Form(const Form &cpy) : _name(cpy._name), _grade(cpy._grade), _execute(cpy._execute)
{
	_isSigned = cpy._isSigned;
}


Form::~Form(){}

std::string Form::getName()
{
	return (_name);
}

bool Form::getSigned()
{
	return (_isSigned);
}

int Form::getGrade()
{
	return (_grade);
}

int Form::getExecute()
{
	return (_execute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form &src)
{
	os << "Form " << src.getName() << " require grade " << src.getGrade() << " to sign, and ";
	os << src.getExecute() << " to execute and the form is ";
	if (src.getSigned() == true)
		os << "already signed." << std::endl;
	else
		os << "not signed." << std::endl;
	return (os);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
