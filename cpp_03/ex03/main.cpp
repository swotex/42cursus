/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:55:37 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 00:27:28 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap	gin("Gin");
	ScavTrap	franc("Franc");
	FragTrap	henri("Henri");
	DiamondTrap	bruno("Bruno");

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
	bruno.guardGate();
	bruno.attack(gin.getName());
	bruno.whoAmI();
	return 0;
}
