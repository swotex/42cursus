/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:57:12 by njegat            #+#    #+#             */
/*   Updated: 2023/08/27 15:30:56 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>


void main_subject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void main_subject_list()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void printc(char c)
{
	std::cout << c << std::endl;
}

void printi(int c)
{
	std::cout << c << std::endl;
}

void my_main()
{
	MutantStack<int> st;
	MutantStack<char, std::vector<char> > stv;

	std::cout << "*** use with MutantStack vector ***" <<  std::endl;
	stv.push('H');
	stv.push('E');
	stv.push('y');
	std::for_each(stv.begin(), stv.end(), printc);

	std::cout << "*** use with MutantStack default (deque) ***" <<  std::endl;
	st.push(45);
	st.push(32);
	st.push(8);
	std::for_each(stv.begin(), stv.end(), printi);
}

int main()
{
	std::cout <<  "---------- Main subject ----------" << std::endl;
	main_subject();
	std::cout <<  "---------- Main subject version list ----------" << std::endl;
	main_subject_list();
	std::cout <<  "---------- Personal main ----------" << std::endl;
	my_main();
	return (0);
}
