/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:08:17 by njegat            #+#    #+#             */
/*   Updated: 2023/08/22 08:31:06 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i=0; i < 4; i++)
		_inventory[i] = NULL;
	_name = "nameless";
}

Character::Character(std::string name)
{
	for (int i=0; i < 4; i++)
		_inventory[i] = NULL;
	_name = name;
}

Character::Character(const Character &cpy)
{
	for (int i=0; i < 4; i++)
		_inventory[i] = cpy._inventory[i]->clone();
	_name = cpy.getName();
}

Character &Character::operator=(const Character &src)
{
	for (int i=0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete (_inventory[i]);
			_inventory[i] = NULL;
		}
	}
	for (int i=0; i < 4; i++)
	{
		if (src._inventory[i])
		{
			_inventory[i] = src._inventory[i]->clone();
		}
		else
			_inventory[i] = NULL;
	}
	_name = src.getName();
	return (*this);
}

Character::~Character()
{
	for (int i=0; i < 4; i++)
	{
		if (_inventory[i])
			delete (_inventory[i]);
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

AMateria *Character::getMateria(unsigned int pos)
{
	if (pos > 3)
	{
		std::cout << "You can't get Materia at this position" << std::endl;
		return (NULL);
	}
	return (_inventory[pos]);
}

void Character::setName(std::string name)
{
	_name = name;
}

void Character::equip(AMateria* m)
{
	for (int i=0; i<4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << "already equip" << std::endl;
			return ;
		}
	}
	for (int i=0; i<4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << _name << " has full inventory" << std::endl;
	delete (m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << idx << " is out of range" << std::endl;
	else if (_inventory[idx])
		_inventory[idx] = NULL;
	else
		std::cout << "this location is already empty" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << idx << " is out of range" << std::endl;
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "this location is empty" << std::endl;
}
