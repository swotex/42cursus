/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:37:15 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 20:01:59 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printUpper(char c)
{
	std::cout << (char)std::toupper(c);
}

void	addOne(int i)
{
	i = i+1;
	std::cout << i;
}


int main(void)
{
	std::string tmp("HeyEveryOne");
	::iter(tmp, 11, printUpper);
	std::cout << std::endl;

	char tmp1[] = "HeyEveryOne";
	::iter(tmp1, 11, printUpper);
	std::cout << std::endl;

	int tmp2[] = {1,2,3,4,5};
	void (*ft)(int) = print;
	::iter(tmp2, 5, ft);
	std::cout << std::endl;
	::iter(tmp2, 5, addOne);
	std::cout << std::endl;
	
	return 0;
}
