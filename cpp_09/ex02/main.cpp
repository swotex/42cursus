/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:14:15 by njegat            #+#    #+#             */
/*   Updated: 2023/09/22 23:43:52 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printVector(std::vector<unsigned int> array)
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid number argument" << std::endl;
		return (1);
	}

	std::string input;
	input.append(argv[1]);
	for (int i = 2; argv[i]; i++)
	{
		input.append(" ");
		input.append(argv[i]);
	}

	PmergeMe merge;

	if (merge.sortVector(input) != 0)
		return (1);
	if (merge.sortDeque(input) != 0)
		return (1);

	std::vector<unsigned int> resv = merge.getSortedVector();
	std::deque<unsigned int> resd = merge.getSortedDeque();

	std::cout << "Before:\t";
	printVector(merge.getNotSortedVector());
	std::cout << "After:\t";
	printVector(resv);

	std::cout << "Time to process a range of " << resv.size() << " elements with std::vector : " << merge.getTimeVector() << " us" << std::endl;
	std::cout << "Time to process a range of " << resd.size() << " elements with std::deque : " << merge.getTimeDeque() << " us" << std::endl;

	return (0);
}
