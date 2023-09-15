/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:39:42 by njegat            #+#    #+#             */
/*   Updated: 2023/07/31 08:57:20 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	printReturn(bool pos)
{
	if (pos == true)
		std::cout << "Point is inside of the triangle" << std::endl;
	else
		std::cout << "Point is not inside of the triangle" << std::endl;
}

int main( void )
{
	bool	back;

	// point inside of triangle
	back = bsp(Point(-2.61711f,3.69389f), Point(-1.4944f,-3.30273f), Point(1.30425f,-1.95222f), Point(-1.38275f,1.90176f));
	printReturn(back);
	// point outside of triangle
	back = bsp(Point(2.22259f,2.31257f), Point(0.47445f,0.71644f), Point(5.86246f,0.15906f), Point(5.16995f,0.20128f));
	printReturn(back);
	// point inside of triangle
	back = bsp(Point(-0.44008f,0.16385f), Point(-0.26732f,-0.49839f), Point(0.30854f,0.3654f), Point(0.30526f,0.36328f));
	printReturn(back);
	// point on the segment of triangle
	back = bsp(Point(-0.19255f,0.11508f), Point(-0.12102f,0.02766f), Point(0.29819f,0.34357f), Point(0.19088f,0.26270f));
	printReturn(back);
	// point on the point of triangle
	back = bsp(Point(0.1325892f,0.7213373f), Point(0.4424891f,0.7396495f), Point(0.1523101f,0.7100682f), Point(0.4424891f,0.7396495f));
	printReturn(back);
	return 0;
}
