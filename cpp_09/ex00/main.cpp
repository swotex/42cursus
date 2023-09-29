/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:37:59 by njegat            #+#    #+#             */
/*   Updated: 2023/09/29 02:11:49 by njegat           ###   ########.fr       */
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
	
	return (0);
}
