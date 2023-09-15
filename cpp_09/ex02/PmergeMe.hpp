/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:29 by njegat            #+#    #+#             */
/*   Updated: 2023/09/15 17:02:18 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe(std::string line);
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();
		std::vector<unsigned int> getSortedVector();
		std::deque<unsigned int> getSortedDeque();
		double getTimeVector() const;
		double getTimeDeque() const;
		void sort();
		class BadEntryException : public std::exception
		{
			const char *what() const throw();
		};
	private:
		bool _sorted;
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
		std::vector<unsigned int> _vecRes;
		std::deque<unsigned int> _deqRes;
		double _timeVec;
		double _timeDec;
		void fillArrays(std::string line);
		std::vector<unsigned int> fordJohnsonVector(std::vector<unsigned int> &array);
		void recursivelySortVector(std::vector<std::pair<unsigned int, unsigned int> > paired);
		void addInRes(std::vector<std::pair<unsigned int, unsigned int> > paired);
		PmergeMe();
};

#endif
