/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:28:58 by njegat            #+#    #+#             */
/*   Updated: 2023/09/09 06:53:29 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

RPN::RPN(std::string line)
{
	_line = line;
}

RPN::RPN(const RPN &cpy)
{
	_line = cpy._line;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		return (*this);
	_line = src._line;
	return (*this);
}

RPN::~RPN(){}

static bool goodChar(char c)
{
	if (std::isdigit(c) != 0)
		return (true);
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);
	else
		return (false);
}

void RPN::resolve()
{
	std::stack<int> st;
	int tmp;

	for (int i = 0; _line[i]; i++)
	{
		if (_line[i] == ' ')
			continue;
		if (goodChar(_line[i]) == false)
		{
			std::cout << "Error : Invalid entry" << std::endl;
			return ;
		}
		if (std::isdigit(_line[i]) != 0)
			st.push((int)(_line[i] - 48));
		else
		{
			if (st.size() < 2)
			{
				std::cout << "Error : Invalid entry" << std::endl;
				return ;
			}
			if (_line[i] == '+')
			{
				tmp = st.top();
				st.pop();
				tmp = st.top() + tmp;
				st.pop();
				st.push(tmp);
			}
			else if (_line[i] == '-')
			{
				tmp = st.top();
				st.pop();
				tmp = st.top() - tmp;
				st.pop();
				st.push(tmp);
			}
			else if (_line[i] == '*')
			{
				tmp = st.top();
				st.pop();
				tmp = st.top() * tmp;
				st.pop();
				st.push(tmp);
			}
			else if (_line[i] == '/')
			{
				tmp = st.top();
				st.pop();
				if (tmp == 0)
				{
					std::cout << "Error : divide by zero" << std::endl;
					return ;
				}
				tmp = st.top() / tmp;
				st.pop();
				st.push(tmp);
			}
		}
	}
	if (st.size() > 1)
		std::cout << "Error : Invalid entry" << std::endl;
	else
		std::cout << st.top() << std::endl;
}
