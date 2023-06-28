/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:57:23 by njegat            #+#    #+#             */
/*   Updated: 2023/06/09 10:00:30 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &fix);
	Fixed & operator = (const Fixed &fix);
	~Fixed();
	int		getRawBits(void);
	void	setRawBits(int const raw);

private:
	int					fixPoint;
	static const int	nfBits = 8;
};

#endif