/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:45 by njegat            #+#    #+#             */
/*   Updated: 2023/08/17 21:25:10 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
	std::cout << name << " is created (DiamondTrap)" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dia) : ClapTrap(dia.name), ScavTrap(dia.name), FragTrap(dia.name)
{
	this->name = dia.name;
	this->hitPoints = dia.hitPoints;
	this->energyPoints = dia.energyPoints;
	this->attackDamage = dia.attackDamage;
	std::cout << name << " is created by copy (DiamondTrap)" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &dia)
{
	this->hitPoints = dia.hitPoints;
	this->energyPoints = dia.energyPoints;
	this->attackDamage = dia.attackDamage;
	this->name = dia.name;
	return (*this);
}

void		DiamondTrap::whoAmI(void)
{
	std::cout << "hi, my DiamondTrap name is : " << this->name << ", and my ClapTrap name is : " << ClapTrap::getName() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << name << " is deleted (DiamondTrap)" << std::endl;
}
