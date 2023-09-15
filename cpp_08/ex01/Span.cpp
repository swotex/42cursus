/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:29:08 by njegat            #+#    #+#             */
/*   Updated: 2023/09/06 22:02:10 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _size(n){}

Span::Span(const Span &cpy) : _array(cpy._array), _size(cpy._size){}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	_array = src._array;
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int nb)
{
	if (_array.size() < _size)
	{
		try
		{
			_array.push_back(nb);
		}
		catch(const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	else
		throw FullException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin,end) + _array.size() <= _size)
	{
		try
		{
			_array.insert(_array.end()--, begin, end);
		}
		catch(const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	else
		throw FullException();
}

void Span::printSpan()
{
	std::vector<int>::iterator tmp;
	tmp = _array.begin();
	for (int i=0; i < (int)_array.size(); i++)
	{
		if (i > 0)
			std::cout << "-";
		std::cout << *tmp;
		tmp++;
	}
	std::cout << std::endl;
}

int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw MissingNbException();
		
	std::sort(_array.begin(), _array.end());
	std::vector<int>::iterator tmp = _array.begin();
	int	shortlenth = 2147483647;
	
	while (tmp + 1 != _array.end() - 1)
	{
		shortlenth = std::min(shortlenth, *(tmp + 1) - *tmp);
		tmp++;
	}
	return (shortlenth);
}

int Span::longestSpan()
{
	if (_array.size() < 2)
		throw MissingNbException();
		
	std::sort(_array.begin(), _array.end());
	std::vector<int>::iterator tmp = _array.begin();
	int i;

	i = *tmp;
	tmp = _array.end();
	tmp--;
	return (*tmp - i);
}

void Span::addManyNumber(int nb)
{
	try
	{
		std::srand(std::time(NULL));
		for (int i=0; i < nb; i++)
			addNumber(std::rand());
	}
	catch(const std::exception& err)
	{
		std::cerr << "Error : " << err.what() << std::endl;
	}
}

const char *Span::FullException::what() const throw()
{
	return ("This array is full or too large addition");
}
const char *Span::MissingNbException::what() const throw()
{
	return ("not enough number in the array");
}
