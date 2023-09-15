/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:42:20 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 19:51:12 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
	public:
		Array() : _array(new T[0]), _size(0){};
		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for(unsigned int i=0; i < n; i++)
				_array[i] = 0;
		};
		Array(const Array &cpy) : _size(cpy._size)
		{
			_array = new T[cpy._size];
			for(unsigned int i=0; i<cpy._size; i++)
				_array[i] = cpy._array[i];
		};
		Array &operator=(const Array &src)
		{
			if (this == &src)
				return (*this);
			if (_size < src._size)
				throw std::exception();
			for(unsigned int i=0; i<src._size; i++)
				_array[i] = src._array[i];
			return (*this);
		};
		~Array(){delete[] _array;};
		unsigned int	size() const
		{
			return (_size);
		};
		T &operator[](int index) const
		{
			if ((unsigned int)index >= _size)
				throw std::exception();
			return (_array[index]);
		};
	private:
		T *_array;
		const unsigned int _size;
};

#endif
