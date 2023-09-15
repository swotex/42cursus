/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:55:37 by njegat            #+#    #+#             */
/*   Updated: 2023/06/25 16:30:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	gin("Gin");
	ScavTrap	franc("Franc");
	FragTrap	henri("Henri");

	gin.attack(franc.getName());
	franc.takeDamage(0);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	franc.guardGate();
	franc.attack(gin.getName());
	henri.attack(franc.getName());
	henri.highFivesGuys();
	return 0;
}
