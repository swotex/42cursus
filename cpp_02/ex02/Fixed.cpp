/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:01:56 by njegat            #+#    #+#             */
/*   Updated: 2023/06/15 17:23:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixPoint = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	fixPoint = nb << nfBits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
	fixPoint = (int)roundf(nb * (1 << nfBits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed &Fixed::operator= (const Fixed &fix)
{
	this->fixPoint = fix.fixPoint;
	// std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

bool Fixed::operator> (const Fixed &fix)
{
	return (this->fixPoint > fix.fixPoint);
}

bool Fixed::operator< (const Fixed &fix)
{
	return (this->fixPoint < fix.fixPoint);
}

bool Fixed::operator>= (const Fixed &fix)
{
	return (this->fixPoint >= fix.fixPoint);
}

bool Fixed::operator<= (const Fixed &fix)
{
	return (this->fixPoint <= fix.fixPoint);
}

bool Fixed::operator== (const Fixed &fix)
{
	return (this->fixPoint == fix.fixPoint);
}

bool Fixed::operator!= (const Fixed &fix)
{
	return (this->fixPoint != fix.fixPoint);
}

Fixed Fixed::operator+ (const Fixed &fix)
{
	Fixed	tmp(this->toFloat() + fix.toFloat());
	return (tmp);
}

Fixed Fixed::operator- (const Fixed &fix)
{
	Fixed	tmp(this->toFloat() - fix.toFloat());
	return (tmp);
}

Fixed Fixed::operator* (const Fixed &fix)
{
	Fixed	tmp(this->toFloat() * fix.toFloat());
	return (tmp);
}

Fixed Fixed::operator/ (const Fixed &fix)
{
	Fixed	tmp(this->toFloat() / fix.toFloat());
	return (tmp);
}

Fixed Fixed::operator++ (int)
{
	Fixed	tmp;

	tmp.fixPoint = fixPoint++;
	return (tmp);
}

Fixed Fixed::operator-- (int)
{
	Fixed	tmp;

	tmp.fixPoint = fixPoint--;
	return (tmp);
}

Fixed &Fixed::operator++ ()
{
	Fixed	&tmp = *this;
	
	tmp.fixPoint = ++fixPoint;
	return (tmp);
}

Fixed &Fixed::operator-- ()
{
	Fixed	&tmp = *this;
	
	tmp.fixPoint = --fixPoint;
	return (tmp);
}

std::ostream & operator<< (std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}

int	Fixed::getRawBits()
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fixPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixPoint = raw;
}

float	Fixed::toFloat() const
{
	return ((float)fixPoint / (1 << nfBits));
}

int	Fixed::toInt() const
{
	return (fixPoint >> nfBits);
}

Fixed & Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	else
		return (fix2);
}
Fixed Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	Fixed	tmp1 = fix1;
	Fixed	tmp2 = fix2;
	
	if (tmp1 < tmp2)
		return (tmp1);
	else
		return (tmp2);
}
Fixed & Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	else
		return (fix2);
}

Fixed Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	Fixed	tmp1 = fix1;
	Fixed	tmp2 = fix2;
	
	if (tmp1 > tmp2)
		return (tmp1);
	else
		return (tmp2);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}