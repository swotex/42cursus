/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:55:37 by njegat            #+#    #+#             */
/*   Updated: 2023/08/17 21:19:41 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	gin("Gin");
	ScavTrap	franc("Franc");

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
	ScavTrap	franc2("Franc2");
	std::cout << franc.getName() << std::endl;
	std::cout << franc2.getName() << std::endl;
	franc2 = franc;
	std::cout << franc.getName() << std::endl;
	std::cout << franc2.getName() << std::endl;

	return 0;
}
