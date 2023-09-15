/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:01:28 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 08:54:28 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &cpy) : AMateria("cure")
{
	_type = cpy.getType();
}

Cure &Cure::operator=(const Cure &src)
{
	_type = src.getType();
	return (*this);
}

void Cure::use(ICharacter &character)
{
	std::cout << "* heals " << character.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *cMateria;
	try
	{
		cMateria = new Cure(*this);
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << "bad alloc : " << ba.what() << std::endl;
		return (NULL);
	}
	return (cMateria);
}

Cure::~Cure(){}
