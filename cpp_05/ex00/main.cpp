/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 06:04:22 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 07:08:44 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	

	return (0);
}
