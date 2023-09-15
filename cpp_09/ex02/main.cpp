/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:15 by njegat            #+#    #+#             */
/*   Updated: 2023/09/15 15:58:42 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::string input;

	for (int i = 1; argv[i]; i++)
	{
		input.append(argv[i]);
		input.append(" ");
	}

	std::cout << input << std::endl;

	try
	{
		PmergeMe test = PmergeMe(argv[1]);

		std::vector<unsigned int> vec1 = test.getSortedVector();
		std::cout << "Time vec : " << test.getTimeVector() << " us"<< std::endl;
		std::deque<unsigned int> dec1 = test.getSortedDeque();
		std::cout << "Time dec : " << test.getTimeDeque() << " us"<< std::endl;


			for (int i = 0; i<(int)vec1.size(); i++)
			{
				std::cout << vec1[i] << " - ";
			}
			std::cout << std::endl;
			for (int i = 0; i<(int)dec1.size(); i++)
			{
				std::cout << dec1[i] << " - ";
			}
			std::cout << std::endl;

	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
	
	return (0);
}
