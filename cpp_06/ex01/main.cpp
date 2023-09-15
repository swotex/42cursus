/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:13:53 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 14:09:30 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data dt;
	uintptr_t tmp = 0;

	dt.content = "coucou1";
	dt.number = 4;

	tmp = Serializer::serialize(&dt);
	std::cout << tmp << std::endl;

	Data *newData = Serializer::deserialize(tmp);
	std::cout << newData->content << std::endl;
	std::cout << newData->number << std::endl;
	std::cout << newData << " : " << &dt << std::endl;
	return 0;
}
