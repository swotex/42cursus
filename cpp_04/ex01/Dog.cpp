/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:30:13 by njegat            #+#    #+#             */
/*   Updated: 2023/06/29 09:57:40 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	brain = new Brain();
	std::cout << "Default constructor Dog." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.type;
	this->brain = new Brain(*dog.brain);
	std::cout << "constructor by copy Dog." << std::endl;
}

Dog		&Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return (*this);
	this->type = dog.type;
	delete(this->brain);
	this->brain = dog.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << type << " say wouf." << std::endl;
}

Dog::~Dog()
{
	delete (brain);
	std::cout << "Default destructor Dog." << std::endl;
}
	