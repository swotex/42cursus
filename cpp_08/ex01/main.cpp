/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:28:54 by njegat            #+#    #+#             */
/*   Updated: 2023/09/06 22:03:05 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp(6);

	sp.addNumber(12);
	sp.addNumber(21);
	sp.addNumber(22);
	sp.addNumber(45);
	sp.addNumber(8);

	sp.printSpan();
	Span sp2(sp);
	sp.addNumber(48);
	sp2.addNumber(41);
	sp.printSpan();
	sp2.printSpan();
	sp2 = sp;
	sp.printSpan();
	sp2.printSpan();

	try
	{
		sp.addNumber(7);
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}
	
	int shortest = sp.shortestSpan();
	int longest = sp2.longestSpan();
	std::cout << "The shortest is " << shortest;
	std::cout << " and the longest is " << longest << std::endl;
	sp.printSpan();
	sp2.printSpan();
	Span sp3(5);
	try
	{
		int longest = sp3.longestSpan();
		std::cout << "The shortest is " << longest << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	std::vector<int> tmp;
	tmp.push_back(8);
	tmp.push_back(4);
	tmp.push_back(7);
	tmp.push_back(234);
	tmp.push_back(9);
	tmp.push_back(25);
	try
	{
		sp3.addNumber(tmp.begin(), tmp.end());
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}
	try
	{
		sp3.addNumber(++tmp.begin(), tmp.end());
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}
	sp3.printSpan();
	

	std::cout << "---------- 15 000 Numbers ----------" << std::endl;

	Span arr(15000);
	arr.addManyNumber(15009);
	std::cout << "The shortest : " << arr.shortestSpan() << std::endl;
	std::cout << "The longest : " << arr.longestSpan() << std::endl;
	// arr.printSpan();
	return 0;
}
