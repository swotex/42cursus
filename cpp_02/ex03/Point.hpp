/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:05:32 by njegat            #+#    #+#             */
/*   Updated: 2023/07/31 05:31:08 by njegat           ###   ########.fr       */
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
		Fixed	getPointX();
		Fixed	getPointY();
		~Point();
	private:
		Point & operator = (const Point &pt);
		const Fixed	x;
		const Fixed	y;
};

#endif
