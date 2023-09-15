/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:12:54 by njegat            #+#    #+#             */
/*   Updated: 2023/06/29 09:58:26 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	this->brain = new Brain();
	std::cout << "Default constructor Cat." << std::endl;
}

Cat::Cat(const Cat &ct)
{
	this->type = ct.type;
	this->brain = ct.brain;
	std::cout << "Constructor by copy Cat." << std::endl;
}

Cat	&Cat::operator=(const Cat &ct)
{
	if (this == &ct)
		return (*this);
	this->type = ct.type;
	delete (this->brain);
	this->brain = new Brain(*ct.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << type << " say miaou." << std::endl;
}

Cat::~Cat()
{
	delete (brain);
	std::cout << "Default destructor Cat." << std::endl;
}
