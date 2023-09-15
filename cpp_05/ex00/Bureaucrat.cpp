/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 05:24:04 by njegat            #+#    #+#             */
/*   Updated: 2023/08/18 05:47:42 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless")
{
	_grade = 75;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	_grade = 75;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	_grade = cpy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName()
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else if (_grade - 1 > 150)
		throw GradeTooLowException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 < 1)
		throw GradeTooHighException();
	else if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrementGrade(int addGrade)
{
	if (_grade - addGrade < 1)
		throw GradeTooHighException();
	else if (_grade - addGrade > 150)
		throw GradeTooLowException();
	_grade -= addGrade;
}

void Bureaucrat::decrementGrade(int addGrade)
{
	if (_grade + addGrade < 1)
		throw GradeTooHighException();
	else if (_grade + addGrade > 150)
		throw GradeTooLowException();
	_grade += addGrade;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &src)
{
	stream << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (stream);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too Low grade");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}
