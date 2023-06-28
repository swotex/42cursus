/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:12:01 by njegat            #+#    #+#             */
/*   Updated: 2023/06/09 08:38:58 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	test;

	if (argc != 1)
	{
		for (int i=1; argv[i]; i++)
		{
			std::cout << "User test " << i << " : " << argv[i] << std::endl;
			test.complain(argv[i]);
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Personnal test :" << std::endl;
	std::cout << std::endl;
	std::cout << "Test debug :" << std::endl;
	test.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Test error :" << std::endl;
	test.complain("ERROR");
	std::cout << std::endl;
	std::cout << "Test info :" << std::endl;
	test.complain("INFO");
	std::cout << std::endl;
	std::cout << "Test warning :" << std::endl;
	test.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Test wrong word :" << std::endl;
	test.complain("HEY");
	return 0;
}
