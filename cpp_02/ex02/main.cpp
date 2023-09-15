/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:39:42 by njegat            #+#    #+#             */
/*   Updated: 2023/07/31 05:28:43 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------- My test ----------" << std::endl;

	Fixed ft(12.21F);
	Fixed sc(32);

	if (ft >= sc)
		std::cout << ft << " >= " << sc << std::endl;
	std::cout << ft << " + " << sc << " = " << ft + sc << std::endl;
	std::cout << ft << " * " << sc << " = " << ft * sc << std::endl;
	std::cout << ft << " / " << sc << " = " << ft / sc << std::endl;
	std::cout << ft << " - " << sc << " = " << ft - sc << std::endl;
	if (ft != sc)
		std::cout << ft << " != " << sc << std::endl;
	return 0;
}