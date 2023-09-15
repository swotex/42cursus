/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:11:35 by njegat            #+#    #+#             */
/*   Updated: 2023/08/17 21:23:11 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << name << " is created (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << name << " is created by copy (ClapTrap)" << std::endl;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &scav)
{
	this->hitPoints = scav.hitPoints;
	this->energyPoints = scav.energyPoints;
	this->attackDamage = scav.attackDamage;
	this->name = scav.name;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->name << " is now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints <=0 || energyPoints <=0)
	{
		std::cout << "I can't do anything" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage! (ScavTrap)" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " is deleted (ScavTrap)" << std::endl;
}
