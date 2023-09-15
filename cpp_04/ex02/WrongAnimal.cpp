/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:58:54 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 06:02:33 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	std::cout << "Constructor by name WrongAnimal." << std::endl;
	this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &an)
{
	this->type = an.type;
	std::cout << "Constructor by copy WrongAnimal." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &an)
{
	this->type = an.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void		WrongAnimal::makeSound(void) const
{
	if (type.empty())
		std::cout << "undifined WrongAnimal";
	else
		std::cout << type;
	std::cout << " make sound." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor WrongAnimal." << std::endl;
}
