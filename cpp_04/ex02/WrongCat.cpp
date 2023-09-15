/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:12:54 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 06:02:17 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat &ct)
{
	this->type = ct.type;
	std::cout << "Constructor by copy WrongCat." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &ct)
{
	this->type = ct.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << type << " say miaou." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Default destructor WrongCat." << std::endl;
}
