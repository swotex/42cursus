/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:47:00 by njegat            #+#    #+#             */
/*   Updated: 2023/08/29 12:39:54 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

class NotFoundException : public std::exception
{
	const char *what() const throw()
	{
		return ("Not found");
	}
};

template<typename T>
typename T::iterator easyfind(T &cont, int i)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw NotFoundException();
	else
		return(it);
}

#endif