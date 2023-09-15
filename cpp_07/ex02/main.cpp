/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:38:41 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 19:56:06 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> tab(5);
	
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 0;

	std::cout << "---------- print tab size 5 ----------" << std::endl;

	std::cout << tab[0] << tab[1] << tab[3] << std::endl;
	std::cout << tab.size() << std::endl;

	std::cout << "---------- add at 12 on tab size 5 ----------" << std::endl;

	try
	{
		std::cout << tab[12] << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	std::cout << "---------- tab size 3 and construtor by copy ----------" << std::endl;

	Array<char> tab1(3);
	
	tab1[0] = 'H';
	tab1[1] = 'e';
	tab1[2] = 'y';

	Array<char> tab2(tab1);
	Array<char> tab3;
	Array<char> tab4(3);
	std::cout << tab1[0] << tab1[1] << tab1[2] << std::endl;
	std::cout << tab2[0] << tab2[1] << tab2[2] << std::endl;

	std::cout << "---------- operator = tab(0) <- tab(3) ----------" << std::endl;

	try
	{
		tab3 = tab1;
		std::cout << tab3[0] << tab3[1] << tab3[2] << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	std::cout << "---------- operator = tab(3) <- tab(3) ----------" << std::endl;

	try
	{
		tab4 = tab1;
		std::cout << tab4[0] << tab4[1] << tab4[2] << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}

	return 0;
}
