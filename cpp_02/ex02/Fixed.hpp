/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:57:23 by njegat            #+#    #+#             */
/*   Updated: 2023/06/15 17:23:47 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &fix);
	Fixed & operator = (const Fixed &fix);
	bool operator > (const Fixed &fix);
	bool operator < (const Fixed &fix);
	bool operator >= (const Fixed &fix);
	bool operator <= (const Fixed &fix);
	bool operator == (const Fixed &fix);
	bool operator != (const Fixed &fix);
	Fixed operator + (const Fixed &fix);
	Fixed operator - (const Fixed &fix);
	Fixed operator * (const Fixed &fix);
	Fixed operator / (const Fixed &fix);
	Fixed operator ++ (int);
	Fixed operator -- (int);
	Fixed & operator ++ (void);
	Fixed & operator -- (void);
	~Fixed();
	static Fixed & min(Fixed &fix1, Fixed &fix2);
	static Fixed min(const Fixed &fix1, const Fixed &fix2);
	static Fixed & max(Fixed &fix1, Fixed &fix2);
	static Fixed max(const Fixed &fix1, const Fixed &fix2);
	int		getRawBits(void);
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					fixPoint;
	static const int	nfBits = 8;
};

std::ostream & operator << (std::ostream &os, const Fixed &fix);

#endif