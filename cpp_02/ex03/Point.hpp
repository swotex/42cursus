/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:05:32 by njegat            #+#    #+#             */
/*   Updated: 2023/06/16 17:41:05 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const float nbx, const float nby);
	Point(const Point &cpy);
	Point & operator = (const Point &pt);
	// void	setPointX(Fixed nbx);
	// void	setPointY(Fixed nby);
	Fixed	getPointX();
	Fixed	getPointY();
	~Point();
private:
	const Fixed	x;
	const Fixed	y;
};

#endif
