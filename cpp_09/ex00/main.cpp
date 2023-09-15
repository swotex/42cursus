/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:37:59 by njegat            #+#    #+#             */
/*   Updated: 2023/08/29 16:58:21 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of argument" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange change(argv[1]);
		change.execute();
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}



	// std::map<std::string, float> test;

	// test.insert( std::pair<std::string,float>("2023-03-15", 23.5) );
	// test.insert( std::pair<std::string,float>("2022-03-15", 12) );
	// test.insert( std::pair<std::string,float>("2023-02-13", 5) );
	// test.insert( std::pair<std::string,float>("2023-09-29", 3.1) );
	// test.insert( std::pair<std::string,float>("2023-01-01", 56.7) );



	// for (std::map<std::string, float>::iterator it = test.begin(); it != test.end(); it++)
	// 	std::cout << it->first << " ==> " << it->second << std::endl;

	// std::map<std::string, float>::iterator i = test.find("2022-12-12");
	// if (i == test.end())
	// 	std::cerr << "Errr" <<  std::endl;
	// else
	// 	std::cout << i->first << std::endl;
	
	return (0);
}
