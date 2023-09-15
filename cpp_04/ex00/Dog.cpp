/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:30:13 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 07:48:52 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Default constructor Dog." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.type;
	std::cout << "constructor by copy Dog." << std::endl;
}

Dog		&Dog::operator=(const Dog &dog)
{
	this->type = dog.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << type << " say wouf." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default destructor Dog." << std::endl;
}
	