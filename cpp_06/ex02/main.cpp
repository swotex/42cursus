/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:17:51 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 15:09:55 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int main()
{
	std::srand(std::time(NULL));
	Base *tmp;
	
	for (int i=0; i < 10; i++)
	{
		tmp = Utils::generate();
		Utils::identify(tmp);
		Base &tmp2 = *tmp;
		Utils::identify(tmp2);
		delete (tmp);
		std::cout << std::endl;
	}
}