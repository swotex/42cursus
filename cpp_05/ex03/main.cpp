/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 06:04:22 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 14:07:26 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat bill("Bill", 146);
	Bureaucrat biff("Biff", 5);
	Intern jiji;
	
	AForm *f1;
	AForm *f2;
	AForm *f3;
	AForm *ftest;

	std::cout << " -------------------- Intern create form ------------------- " << std::endl << std::endl;

	try
	{
		f1 = jiji.makeForm("ShruBbery Form", "garden");
		f2 = jiji.makeForm("RoboToMy Request", "ty");
		f3 = jiji.makeForm("PresidEnTial Form", "Bruno");
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	try
	{
		ftest = jiji.makeForm("Hey Form", "garden");
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	std::cout << std::endl << " -------------------- Shrubbery Form ------------------- " << std::endl << std::endl;
	
	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(*f1);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(*f1);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(*f1);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(*f1);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(*f1);

	std::cout << std::endl << " -------------------- Robotomy Form ------------------- " << std::endl << std::endl;
	
	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(*f2);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(*f2);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(*f2);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(*f2);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(*f2);

	std::cout << std::endl << " -------------------- Presidential Form ------------------- " << std::endl << std::endl;

	std::cout << " ********** Not signed ********** " << std::endl;
	biff.executeForm(*f3);

	std::cout << " ********** Can't sign ********** " << std::endl;
	bill.signForm(*f3);

	std::cout << " ********** sign ********** " << std::endl;
	biff.signForm(*f3);

	std::cout << " ********** can't exec ********** " << std::endl;
	bill.executeForm(*f3);

	std::cout << " ********** exec ********** " << std::endl;
	biff.executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;

	return (0);
}
