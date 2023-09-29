/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:29 by njegat            #+#    #+#             */
/*   Updated: 2023/09/29 02:04:05 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <regex.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe()
{
	_timeVec = 0;
	_timeDec = 0;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	_vec.operator=(cpy._vec);
	_deq.operator=(cpy._deq);
	_vecRes.operator=(cpy._vecRes);
	_deqRes.operator=(cpy._deqRes);
	_timeVec = cpy._timeVec;
	_timeDec = cpy._timeDec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);
	_vec.operator=(src._vec);
	_deq.operator=(src._deq);
	_vecRes.operator=(src._vecRes);
	_deqRes.operator=(src._deqRes);
	_timeVec = src._timeVec;
	_timeDec = src._timeDec;
	return (*this);
}

PmergeMe::~PmergeMe(){}

// *************************************************************************************
// ****************************** fordjonhson vector sort ******************************
// *************************************************************************************

int binarySearch(std::vector<unsigned int> array, int low, int high, unsigned int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}


std::vector<unsigned int> recursiveSort(std::vector<unsigned int> maxPair)
{
	if (maxPair.size() == 1)
		return maxPair;

	int mid = maxPair.size() / 2;
	std::vector<unsigned int> left(maxPair.begin(), maxPair.begin() + mid);
	std::vector<unsigned int> right(maxPair.begin() + mid, maxPair.end());

	left = recursiveSort(left);
	right = recursiveSort(right);

	std::vector<unsigned int> result;
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j]) {
			result.push_back(left[i]);
			i++;
		} else {
			result.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}
	while (j < right.size())
	{
		result.push_back(right[j]);
		j++;
	}
	return result;
}

std::vector<std::pair<unsigned int, unsigned int> > swapPair(std::vector<std::pair<unsigned int, unsigned int> > paired, size_t start, size_t len)
{
	int i = 0, tmp = 0;
	std::vector<std::pair<unsigned int, unsigned int> > out;

	while (i < (int)start && i < (int)paired.size())
	{
		out.push_back(paired[i]);
		i++;
	}
	tmp = i + len - 1;
	while (tmp >= (int)paired.size())
		tmp--;
	while (tmp >= i)
	{
		out.push_back(paired[tmp]);
		tmp--;
	}
	i = i + len;
	while (i < (int)paired.size())
	{
		out.push_back(paired[i]);
		i++;
	}
	return (out);
}

std::vector<unsigned int> fordJohnsonVector(std::vector<unsigned int> &array)
{
	std::vector<std::pair<unsigned int, unsigned int> > paired;
	std::vector<unsigned int> maxPair;
	size_t i = 0;

	// Make pair and add max in array
	while (i + 1 < array.size())
	{
		int max = std::max(array[i], array[i + 1]);
		int min = std::min(array[i], array[i + 1]);
		paired.push_back(std::make_pair(min, max));
		maxPair.push_back(max);
		i += 2;
	}

	// sort max and add the min of first max
	std::vector<unsigned int> tmp = recursiveSort(maxPair);
	for (size_t i = 0; i < paired.size(); i++)
	{
		if (paired[i].second == tmp[0])
		{
			tmp.insert(tmp.begin(), paired[i].first);
			paired.erase(paired.begin() + i);
			break;
		}
	}

	// swap min on suit 2, 2, 6...
	size_t nb0 = 2, nb1 = 2;
	i = 0;
	while (i < paired.size())
	{
		paired = swapPair(paired, i, nb0);
		i += nb0;
		if (i < paired.size())
		{
			paired = swapPair(paired, i, nb1);
			i+=nb1;
		}
		nb0 = nb0 * 2 + nb1;
		nb1 = nb1 * 2 + nb0;
	}
	
	// add min
	for (size_t i = 0; i < paired.size(); i++)
	{
		int pos = binarySearch(tmp, 0, tmp.size(), paired[i].second);
		pos = binarySearch(tmp, 0, pos, paired[i].first);
		tmp.insert(tmp.begin() + pos, paired[i].first);
	}
	// add odd
	if (array.size() % 2 == 1)
	{
		int pos = binarySearch(tmp, 0, tmp.size()-1, *(array.end() - 1));
		std::cerr << "pos: " << pos << std::endl;
		tmp.insert(tmp.begin() + pos, *(array.end() - 1));
	}
	return (tmp);
}

int fillVector(std::vector<unsigned int> &vec, std::string line)
{
	std::string tmp;
	unsigned int tmpNumber;

	if (line.empty() == true)
		return (1);
	for (size_t i = 0; i < line.size();)
	{
		tmp.clear();
		while (line[i] == ' ')
			i++;
		if (line[i] == 0)
			break;
		for (size_t j = 0; std::isdigit(line[i]) != 0; j++)
		{
			tmp.insert(tmp.begin() + j, line[i]);
			i++;
		}
		if (std::isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != 0)
			return (1);
		if (!(std::istringstream(tmp) >> tmpNumber))
			return (1);
		vec.push_back(tmpNumber);
	}
	return (0);
}

int PmergeMe::sortVector(std::string line)
{
	clock_t start_time, end_time;

	start_time = clock();
	
	if (fillVector(_vec, line) != 0)
	{
		std::cout << "Error : Bad entry" << std::endl;
		return (1);
	}
	if (_vec.size() < 2)
	{
		std::cout << "Error : Invalid argument" << std::endl;
		return (1);
	}

	_vecRes = fordJohnsonVector(_vec);
	end_time = clock();
	_timeVec = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	return (0);
}

// *************************************************************************************
// ****************************** fordjonhson deque sort ******************************
// *************************************************************************************


int binarySearch(std::deque<unsigned int> array, int low, int high, unsigned int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

std::deque<std::pair<unsigned int, unsigned int> > swapPair(std::deque<std::pair<unsigned int, unsigned int> > paired, size_t start, size_t len)
{
	int i = 0, tmp = 0;
	std::deque<std::pair<unsigned int, unsigned int> > out;

	while (i < (int)start && i < (int)paired.size())
	{
		out.push_back(paired[i]);
		i++;
	}
	tmp = i + len - 1;
	while (tmp >= (int)paired.size())
		tmp--;
	while (tmp >= i)
	{
		out.push_back(paired[tmp]);
		tmp--;
	}
	i = i + len;
	while (i < (int)paired.size())
	{
		out.push_back(paired[i]);
		i++;
	}
	return (out);
}

std::deque<unsigned int> recursiveSort(std::deque<unsigned int> maxPair)
{
	if (maxPair.size() == 1)
		return maxPair;

	int mid = maxPair.size() / 2;
	std::deque<unsigned int> left(maxPair.begin(), maxPair.begin() + mid);
	std::deque<unsigned int> right(maxPair.begin() + mid, maxPair.end());

	left = recursiveSort(left);
	right = recursiveSort(right);

	std::deque<unsigned int> result;
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j]) {
			result.push_back(left[i]);
			i++;
		} else {
			result.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}
	while (j < right.size())
	{
		result.push_back(right[j]);
		j++;
	}
	return result;
}

std::deque<unsigned int> fordJohnsonDeque(std::deque<unsigned int> &array)
{
	std::deque<std::pair<unsigned int, unsigned int> > paired;
	std::deque<unsigned int> maxPair;
	size_t i = 0;

	// Make pair and add max in array
	while (i + 1 < array.size())
	{
		int max = std::max(array[i], array[i + 1]);
		int min = std::min(array[i], array[i + 1]);
		paired.push_back(std::make_pair(min, max));
		maxPair.push_back(max);
		i += 2;
	}

	// sort max and add the min of first max
	std::deque<unsigned int> tmp = recursiveSort(maxPair);
	for (size_t i = 0; i < paired.size(); i++)
	{
		if (paired[i].second == tmp[0])
		{
			tmp.insert(tmp.begin(), paired[i].first);
			paired.erase(paired.begin() + i);
			break;
		}
	}

	// swap min on suit 2, 2, 6...
	size_t nb0 = 2, nb1 = 2;
	i = 0;
	while (i < paired.size())
	{
		paired = swapPair(paired, i, nb0);
		i += nb0;
		if (i < paired.size())
		{
			paired = swapPair(paired, i, nb1);
			i+=nb1;
		}
		nb0 = nb0 * 2 + nb1;
		nb1 = nb1 * 2 + nb0;
	}
	
	// add min
	for (size_t i = 0; i < paired.size(); i++)
	{
		int pos = binarySearch(tmp, 0, tmp.size(), paired[i].second);
		pos = binarySearch(tmp, 0, pos, paired[i].first);
		tmp.insert(tmp.begin() + pos, paired[i].first);
	}
	// add odd
	if (array.size() % 2 == 1)
	{
		int pos = binarySearch(tmp, 0, tmp.size() - 1, *(array.end() - 1));
		std::cerr << "pos: " << pos << std::endl;
		tmp.insert(tmp.begin() + pos, *(array.end() - 1));
	}
	return (tmp);
}

int fillDeque(std::deque<unsigned int> &deq, std::string line)
{
	std::string tmp;
	unsigned int tmpNumber;

	if (line.empty() == true)
		return (1);
	for (size_t i = 0; i < line.size();)
	{
		tmp.clear();
		while (line[i] == ' ')
			i++;
		if (line[i] == 0)
			break;
		for (size_t j = 0; std::isdigit(line[i]) != 0; j++)
		{
			tmp.insert(tmp.begin() + j, line[i]);
			i++;
		}
		if (std::isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != 0)
			return (1);
		if (!(std::istringstream(tmp) >> tmpNumber))
			return (1);
		deq.push_back(tmpNumber);
	}
	return (0);
}

int PmergeMe::sortDeque(std::string line)
{
	clock_t start_time, end_time;

	start_time = clock();
	
	if (fillDeque(_deq, line) != 0)
	{
		std::cout << "Error : Bad entry" << std::endl;
		return (1);
	}
	if (_deq.size() < 2)
	{
		std::cout << "Error : Invalid argument" << std::endl;
		return (1);
	}

	_deqRes = fordJohnsonDeque(_deq);
	end_time = clock();
	_timeDec = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	return (0);
}

std::vector<unsigned int> PmergeMe::getSortedVector()
{
	return (_vecRes);
}

std::deque<unsigned int> PmergeMe::getSortedDeque()
{
	return (_deqRes);
}

std::vector<unsigned int> PmergeMe::getNotSortedVector()
{
	return (_vec);
}

double PmergeMe::getTimeVector() const
{
	return (_timeVec);
}

double PmergeMe::getTimeDeque() const
{
	return (_timeDec);
}
