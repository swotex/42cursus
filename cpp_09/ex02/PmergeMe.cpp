/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:29 by njegat            #+#    #+#             */
/*   Updated: 2023/09/15 17:17:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <regex.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(std::string line)
{
	_timeVec = 0;
	_timeDec = 0;
	_sorted = false;
	fillArrays(line);
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	_vec.operator=(cpy._vec);
	_deq.operator=(cpy._deq);
	_timeVec = cpy._timeVec;
	_timeDec = cpy._timeDec;
	_sorted = cpy._sorted;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);
	_vec.operator=(src._vec);
	_deq.operator=(src._deq);
	_timeVec = src._timeVec;
	_timeDec = src._timeDec;
	_sorted = src._sorted;
	return (*this);
}

PmergeMe::~PmergeMe(){}

static bool checkNumber(std::string nb)
{
	for (int i=0; nb[i]; i++)
	{
		if (std::isdigit((int)nb[i]) == false)
			return (false);
	}
	return (true);
}

void PmergeMe::fillArrays(std::string line)
{
	size_t pos = 0;
	std::string stmp;
	unsigned int tmp;

	while (line.find(' ', pos) != std::string::npos)
	{
		stmp = line.substr(pos, (line.find(' ', pos) - pos));
		if (checkNumber(stmp) == false)
			throw BadEntryException();
		if (!(std::istringstream(stmp) >> tmp))
			throw BadEntryException();
		_vec.push_back(tmp);
		_deq.push_back(tmp);
		pos = line.find(' ', pos);
		while (line[pos] == ' ')
			pos++;
	}
	if (pos != std::string::npos)
	{
		if (!(std::istringstream(line.substr(pos)) >> tmp))
			throw BadEntryException();
		_vec.push_back(tmp);
		_deq.push_back(tmp);
	}
}

int binarySearch(std::vector<unsigned int> _vecRes, int low, int high, unsigned int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (_vecRes[mid] == key)
			return mid;
		else if (_vecRes[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int searchInsertPos(std::vector<unsigned int> _vecRes, int low, int high, unsigned int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (_vecRes[mid] == key)
			return mid;
		else if (_vecRes[mid] < key)
			low = mid + 1;
		else
			return mid - 1;
	}
	return -1;
}

void insertionSort(std::vector<unsigned int> &_vecRes, std::pair<unsigned int, unsigned int> pair)
{
	int max = _vecRes.size() - 1;
	int insertPos;

    max = binarySearch(_vecRes, 0, max, pair.second);
	if (max == -1)
	{
		std::cerr << "Error : not found" << std::endl;
		return ;
	}
	insertPos = searchInsertPos(_vecRes, 0, max, pair.first);
	std::cerr << "add (insert sort) -> " << pair.first << std::endl;
	_vecRes.insert(_vecRes.begin() + insertPos, pair.first);
}

void PmergeMe::addInRes(std::vector<std::pair<unsigned int, unsigned int> > paired)
{
	if (_vecRes.empty() == true)
		_vecRes.push_back(paired[0].second);
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = paired.begin();
	while (it != paired.end())
	{
		if (it->second == _vecRes[0])
		{
			_vecRes.insert(_vecRes.begin(), it->first);
			std::cerr << "add (addInRes) -> " << it->first << std::endl;
			paired.erase(it);
			break;
		}
		it++;
	}
	for (int i = 0; i < (int)paired.size(); i++)
	{
		insertionSort(_vecRes, paired[i]);
	}
	
}

void PmergeMe::recursivelySortVector(std::vector<std::pair<unsigned int, unsigned int> > paired)
{
	if (paired.size() < 2)
		return ;
	std::vector<std::pair<unsigned int, unsigned int> > new_paired;
	int i = 0;
	while (i < (int)paired.size() && i + 1 < (int)paired.size())
	{
		new_paired.push_back(std::make_pair(std::min(paired[i].second, paired[i + 1].second), std::max(paired[i].second, paired[i + 1].second)));
		i += 2;
	}
	recursivelySortVector(new_paired);
	addInRes(new_paired);
	// if odd -> add lastone
	if (paired.size() % 2 == 1)
	{
		insertionSort(_vecRes, *paired.end());
	}
}

std::vector<unsigned int> PmergeMe::fordJohnsonVector(std::vector<unsigned int> &array)
{
	std::vector<unsigned int>::iterator it = array.begin();
	std::vector<std::pair<unsigned int, unsigned int> > paired;

	while (it != array.end() && it + 1 != array.end())
	{
		paired.push_back(std::make_pair(std::min(*it, *(it + 1)), std::max(*it, *(it + 1))));
		it += 2;
	}
	recursivelySortVector(paired);
	addInRes(paired);
	// if size == odd -> add lastone
	if (array.size() % 2 == 1)
	{
		int pos = searchInsertPos(_vecRes, 0, _vecRes.size(), array[array.size() - 1]);
		_vecRes.insert(_vecRes.begin() + pos, array[array.size() - 1]);
	}
	return (array);
}

void PmergeMe::sort()
{
	clock_t start_time, end_time;
	start_time = clock();
	_vec = fordJohnsonVector(_vec);
	end_time = clock();
	_timeVec = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	// start_time = clock();
	// _deq = fordJohnsonDeque(_deq);
	// end_time = clock();
	// _timeDec = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	_sorted = true;
}

std::vector<unsigned int> PmergeMe::getSortedVector()
{
	if (_sorted == false)
		sort();
	return (_vecRes);
}

std::deque<unsigned int> PmergeMe::getSortedDeque()
{
	if (_sorted == false)
		sort();
	return (_deq);
}

double PmergeMe::getTimeVector() const
{
	return (_timeVec);
}

double PmergeMe::getTimeDeque() const
{
	return (_timeDec);
}

const char *PmergeMe::BadEntryException::what() const throw()
{
	return ("Error : Bad entry");
}
