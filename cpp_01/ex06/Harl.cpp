/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:41:49 by njegat            #+#    #+#             */
/*   Updated: 2023/07/26 19:07:37 by njegat           ###   ########.fr       */
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
	int			i = 0;

	while (i < 4)
	{
		if(check[i] == level)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		(this->*func[0])();
		break;
	case 1:
		for (int j=0; j < 2; j++)
			(this->*func[j])();
		break;
	case 2:
		for (int j=0; j < 3; j++)
			(this->*func[j])();
		break;
	case 3:
		for (int j=0; j < 4; j++)
			(this->*func[j])();
		break;
	default:
		std::cout << "Level error" <<std::endl;
	}
}
