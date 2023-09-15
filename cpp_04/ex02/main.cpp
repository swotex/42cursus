/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:57:41 by njegat            #+#    #+#             */
/*   Updated: 2023/06/29 10:30:40 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog*	ddog = new Dog();
	Dog*	cpydog = new Dog(*ddog);

	std::cout << "--------------------------------" << std::endl;

	ddog->makeSound();
	cpydog->makeSound();

	std::cout << "--------------------------------" << std::endl;
	
	delete (ddog);
	delete (cpydog);

	return 0;
}