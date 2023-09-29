/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:29 by njegat            #+#    #+#             */
/*   Updated: 2023/09/22 23:39:05 by njegat           ###   ########.fr       */
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
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();
		int sortVector(std::string line);
		int sortDeque(std::string line);
		std::vector<unsigned int> getSortedVector();
		std::deque<unsigned int> getSortedDeque();
		std::vector<unsigned int> getNotSortedVector();
		double getTimeVector() const;
		double getTimeDeque() const;
	private: 
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
		std::vector<unsigned int> _vecRes;
		std::deque<unsigned int> _deqRes;
		double _timeVec;
		double _timeDec;
};

#endif
