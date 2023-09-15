/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:26:38 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 08:54:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &cpy) : AMateria("ice")
{
	_type = cpy.getType();
}

Ice &Ice::operator=(const Ice &src)
{
	_type = src.getType();
	return (*this);
}

void Ice::use(ICharacter &character)
{
	std::cout << "* shoots an ice bolt at " << character.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *cMateria;
	try
	{
		cMateria = new Ice(*this);
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << "bad alloc : " << ba.what() << std::endl;
		return (NULL);
	}
	return (cMateria);
}

Ice::~Ice(){}
