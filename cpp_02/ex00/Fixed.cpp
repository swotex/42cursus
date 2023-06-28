/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:01:56 by njegat            #+#    #+#             */
/*   Updated: 2023/06/14 14:01:34 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed &Fixed::operator= (const Fixed &fix)
{
	this->fixPoint = fix.fixPoint;
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixPoint = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}