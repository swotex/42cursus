/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:17:28 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 05:31:14 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[])
{
	std::string	string;
	std::string	*stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;

	std::string &stringREF = string;

	std::cout << "Memory addr : " << &string << std::endl;
	std::cout << "Memory addr held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory addr held by stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value : " << string << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
	return 0;
}
