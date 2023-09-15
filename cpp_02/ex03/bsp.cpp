/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:06:01 by njegat            #+#    #+#             */
/*   Updated: 2023/06/21 03:24:01 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Point	substract(Point p1, Point p2)
{
	Point	tmp((p1.getPointX() - p2.getPointX()).toFloat(), (p1.getPointY() - p2.getPointY()).toFloat());

	return (tmp);
}

static float	product(Point p1, Point p2)
{
	float	tmp;

	tmp = (float)p1.getPointX().toFloat() * p2.getPointY().toFloat();
	tmp = tmp - (float)(p1.getPointY().toFloat() * p2.getPointX().toFloat());
	return (tmp);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	A(a);
	Point	B(b);
	Point	C(c);
	Point	P(point);
	Point	AB = substract(B, A);
	Point	AC = substract(C, A);
	Point	AP = substract(P, A);
	float	ABAP = product(AB, AP);
	float	BCBP = product(substract(C, B), substract(P, B));
	float	CACP = product(substract(A, C), substract(P, C));

	if (ABAP < 0 && BCBP < 0 && CACP < 0)
		return (true);
	else if (ABAP > 0 && BCBP > 0 && CACP > 0)
		return (true);
	else
		return (false);
}
