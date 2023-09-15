/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:24:56 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 04:06:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &cpy)
{
	_type = cpy._type;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	_type = src._type;
	return (*this);
}

AMateria::~AMateria(){}

void AMateria::setType(std::string type)
{
	_type = type;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " use " << _type << std::endl;
}
