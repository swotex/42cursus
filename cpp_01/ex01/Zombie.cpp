/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:51:02 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 05:15:10 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName)
{
	name = newName;
	std::cout << name << " is created" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "(NULL) is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void	Zombie::announce()
{
	if (name.empty())
		std::cout << "noName";
	else
		std::cout << name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
