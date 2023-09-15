/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:29:30 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 15:13:08 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

Base *Utils::generate(void)
{
	switch (std::rand() % 3 + 1)
	{
		case 1 :
			return (new A());
			break;
		case 2 :
			return (new B());
			break;
		default :
			return (new C());
			break;
	}
	return (NULL);
}

void Utils::identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It'a A class *" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It'a B class *" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "It'a C class *" << std::endl;
}

void Utils::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It'a A class &" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "It'a B class &" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "It'a C class &" << std::endl;
	}
	catch(const std::exception& e){}	
}
