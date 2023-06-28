/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:41:49 by njegat            #+#    #+#             */
/*   Updated: 2023/06/09 08:29:34 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "\e[4;34m[DEBUG]\e[0m" << " information" << std::endl;
}

void	Harl::info()
{
	std::cout << "\e[4;36m[INFO]\e[0m" << " about the code" << std::endl;
}

void	Harl::warning()
{
	std::cout << "\e[4;33m[WARNING]\e[0m" << " useless code" << std::endl;
}

void	Harl::error()
{
	std::cout << "\e[4;31m[ERROR]\e[0m" << " the code is totaly break" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	check[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*func[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i < 4; i++)
	{
		if (check[i] == level)
		{
			for (int j=i; j < 4; j++)
				(this->*func[j])();
		}
	}
}
