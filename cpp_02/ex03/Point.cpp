/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:05:50 by njegat            #+#    #+#             */
/*   Updated: 2023/07/10 23:14:22 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed()){}

Point::Point(const float nbx, const float nby): x(Fixed(nbx)), y(Fixed(nby)){}

Point::Point(const Point &cpy): x(cpy.x), y(cpy.y){}

Point & Point::operator = (const Point &pt)
{
	(void)pt;
	return (*this);
}

Fixed	Point::getPointX()
{
	return (this->x);
}

Fixed	Point::getPointY()
{
	return (this->y);
}

Point::~Point(){}
