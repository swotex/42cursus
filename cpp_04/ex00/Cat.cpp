/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:12:54 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 04:48:58 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Default constructor Cat." << std::endl;
}

Cat::Cat(const Cat &ct)
{
	this->type = ct.type;
	std::cout << "Constructor by copy Cat." << std::endl;
}

Cat	&Cat::operator=(const Cat &ct)
{
	this->type = ct.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << type << " say miaou." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default destructor Cat." << std::endl;
}
