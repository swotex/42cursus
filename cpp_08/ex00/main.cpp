/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:47:23 by njegat            #+#    #+#             */
/*   Updated: 2023/08/29 12:40:34 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> tab;

	tab.push_back(7);
	tab.push_back(5);
	tab.push_back(3);
	
	try
	{
		std::vector<int>::iterator it = easyfind(tab, 3);
		std::cout << "Find : " << *it << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(tab, 8);
		std::cout << "Find : " << *it << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}


	std::list<int> myList;

	myList.push_back(5);
	myList.push_back(12);
	myList.push_back(24);
	myList.push_back(2);
	myList.push_back(6);

	try
	{
		std::list<int>::iterator it = easyfind(myList, 2);
		std::cout << "Find : " << *it << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(myList, 67);
		std::cout << "Find : " << *it << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}
}
