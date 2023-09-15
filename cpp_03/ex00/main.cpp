/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:55:37 by njegat            #+#    #+#             */
/*   Updated: 2023/08/17 21:11:35 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	gin("Gin");
	ClapTrap	franc("Franc");

	gin.attack(franc.getName());
	franc.takeDamage(0);
	gin.beRepaired(2147483649);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(12);
	gin.beRepaired(5);
	gin.beRepaired(1);
	gin.beRepaired(1);
	gin.beRepaired(1);
	return 0;
}
