/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 05:24:04 by njegat            #+#    #+#             */
/*   Updated: 2023/08/20 06:30:18 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() == true)
		std::cerr << _name << "  couldn’t sign " << form.getName() << " because is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << _name << "  signed " << form.getName() << std::endl;
		}
		catch(const std::exception& err)
		{
			std::cerr << _name << "  couldn’t sign " << form.getName() << " because " << err.what() << std::endl;
		}
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << this->getName() << " can't execute " << form.getName() << " because " << err.what() << std::endl;
	}
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
