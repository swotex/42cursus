/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:05:50 by njegat            #+#    #+#             */
/*   Updated: 2023/06/16 17:40:55 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed()){}

Point::Point(const float nbx, const float nby): x(Fixed(nbx)), y(Fixed(nby)){}

Point::Point(const Point &cpy): x(cpy.x), y(cpy.y){}

Point & Point::operator = (const Point &pt){}

// void	Point::setPointX(Fixed nbx);

// void	Point::setPointY(Fixed nby);

Fixed	Point::getPointX();

Fixed	Point::getPointY();

Point::~Point();
