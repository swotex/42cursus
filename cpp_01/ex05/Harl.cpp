/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:41:49 by njegat            #+#    #+#             */
/*   Updated: 2023/06/09 07:49:30 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "debugging information" << std::endl;
}

void	Harl::info()
{
	std::cout << "information about the code" << std::endl;
}

void	Harl::warning()
{
	std::cout << "warning useless code" << std::endl;
}

void	Harl::error()
{
	std::cout << "error the code is totaly break" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	check[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*func[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i < 4; i++)
	{
		if (check[i] == level)
			(this->*func[i])();
	}
}
