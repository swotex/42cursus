/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:03:14 by njegat            #+#    #+#             */
/*   Updated: 2023/08/17 21:24:55 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << name << " is created (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
	std::cout << name << " is created by copy (FragTrap)" << std::endl;
}

FragTrap	&FragTrap::operator = (const FragTrap &frag)
{
	this->hitPoints = frag.hitPoints;
	this->energyPoints = frag.energyPoints;
	this->attackDamage = frag.attackDamage;
	this->name = frag.name;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "That's a big highfive !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << name << " is deleted (FragTrap)" << std::endl;
}
