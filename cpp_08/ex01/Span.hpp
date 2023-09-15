/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:29:08 by njegat            #+#    #+#             */
/*   Updated: 2023/08/29 13:46:06 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &cpy);
		Span &operator=(const Span &src);
		~Span();
		void addNumber(int nb);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void printSpan();
		int shortestSpan();
		int longestSpan();
		void addManyNumber(int nb);
		class FullException : public std::exception
		{
			const char *what() const throw();
		};
		class MissingNbException : public std::exception
		{
			const char *what() const throw();
		};
	private:
		Span();
		std::vector<int> _array;
		const unsigned int _size;
};

#endif
