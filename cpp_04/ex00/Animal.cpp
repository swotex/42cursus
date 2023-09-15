/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:58:54 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 04:49:13 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor Animal." << std::endl;
}

Animal::Animal(std::string name)
{
	std::cout << "Constructor by name Animal." << std::endl;
	this->type = name;
}

Animal::Animal(const Animal &an)
{
	this->type = an.type;
	std::cout << "Constructor by copy Animal." << std::endl;
}

Animal &Animal::operator=(const Animal &an)
{
	this->type = an.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (type);
}

void		Animal::makeSound(void) const
{
	if (type.empty())
		std::cout << "undifined";
	else
		std::cout << type;
	std::cout << " make sound." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor Animal." << std::endl;
}
