/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:50:52 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 05:11:43 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*tmp = zombieHorde(5, "Josh");
	for (int i=0; i < 5; i++)
		tmp[i].announce();
	delete[] tmp;
	return 0;
}
