/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:37:32 by njegat            #+#    #+#             */
/*   Updated: 2023/08/28 11:22:44 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename F>
void iter(T &arr, int len, F func)
{
	for (int i=0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void print(T c)
{
	std::cout << c;
}

#endif