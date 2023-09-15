/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 06:04:22 by njegat            #+#    #+#             */
/*   Updated: 2023/08/21 07:03:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bill("Bill", 146);
	Bureaucrat biff("Biff", 5);
	ShrubberyCreationForm f1 = ShrubberyCreationForm("grass");
	RobotomyRequestForm f2 = RobotomyRequestForm("factory");
	PresidentialPardonForm f3 = PresidentialPardonForm("joe");
	

	std::cout << " -------------------- Shrubbery Form ------------------- " << std::endl << std::endl;
	
	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(f1);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(f1);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(f1);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(f1);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(f1);

	std::cout << std::endl << " -------------------- Robotomy Form ------------------- " << std::endl << std::endl;
	
	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(f2);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(f2);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(f2);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(f2);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(f2);

	std::cout << std::endl << " -------------------- Presidential Form ------------------- " << std::endl << std::endl;

	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(f3);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(f3);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(f3);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(f3);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(f3);

	return (0);
}
