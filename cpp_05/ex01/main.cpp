/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 06:04:22 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 10:03:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat bill("Bill", 150);
	Bureaucrat biff("Biff", 1);
	Bureaucrat nameless;

	// decrement exception
	try
	{
		bill.decrementGrade();
	}
	catch(const std::exception  & err)
	{
		std::cerr << "Error : " << err.what() << " for " << bill << std::endl;
	}

	// increment exception
	try
	{
		biff.incrementGrade();
	}
	catch(const std::exception & err)
	{
		std::cerr << "Error : " << err.what() << " for " << biff << std::endl;
	}

	// decrement pass
	try
	{
		nameless.decrementGrade(15);
	}
	catch(const std::exception & err)
	{
		std::cerr << "Error : " << err.what() << " for " << nameless << std::endl;
	}

	// decrement exception
	try
	{
		nameless.decrementGrade(200);
	}
	catch(const std::exception & err)
	{
		std::cerr << "Error : " << err.what() << " for " << nameless << std::endl;
	}
	
	std::cout << "----------- ex01 part -------------" <<std::endl;
	Form f1 = Form();
	Form f2("boo", 12, 5);

	bill.signForm(f2);
	try
	{
		f1.beSigned(bill);
	}
	catch(const std::exception& err)
	{
		std::cerr << bill.getName() << " couldn’t sign " << f1.getName() << " because " << err.what() << std::endl;
	}
	std::cout << "info of form 2 : " << f2 << std::endl;
	biff.signForm(f2);
	std::cout << "info of form 2 : " << f2 << std::endl;
	biff.signForm(f2);

	return (0);
}
