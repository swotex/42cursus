/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:50:52 by njegat            #+#    #+#             */
/*   Updated: 2023/07/20 00:33:52 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie	*first = newZombie("Josh");
	first->announce();
	delete first;
	randomChump("Itashi");
	return 0;
}
