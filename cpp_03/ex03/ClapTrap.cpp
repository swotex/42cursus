/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:56:06 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 10:07:28 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << name << " is created (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
	std::cout << name << " is created by copy (ClapTrap)" << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &clap)
{
	this->hitPoints = clap.hitPoints;
	this->energyPoints = clap.energyPoints;
	this->attackDamage = clap.attackDamage;
	this->name = clap.name;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints <=0 || energyPoints <=0)
	{
		std::cout << "I can't do anything" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 2147483647)
	{
		std::cout << "invalid amount" << std::endl;
		return ;
	}
	hitPoints -= amount;
	std::cout << name << " take " << amount << " damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > 2147483647)
	{
		std::cout << "invalid amount" << std::endl;
		return ;
	}
	if (hitPoints <=0 || energyPoints <=0)
	{
		std::cout << "I can't do anything" << std::endl;
		return ;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << name << " get " << amount << " hit points. New hit points : " << hitPoints << std::endl;
}

std::string	ClapTrap::getName()
{
	return (name);
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " is destroyed (ClapTrap)" << std::endl;
}
