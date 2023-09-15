/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:57:41 by njegat            #+#    #+#             */
/*   Updated: 2023/06/29 10:03:27 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << "--------------------------------" << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;

	std::cout << "--------------------------------" << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	wcat->makeSound();

	std::cout << "--------------------------------" << std::endl;

	delete(meta);
	delete(dog);
	delete(cat);
	delete(wcat);

	std::cout << std::endl;
	std::cout << "****************-ex01-***************" << std::endl;
	std::cout << std::endl;

	Animal	*arr[4];
	arr[0] = new Dog();
	arr[1] = new Cat();
	arr[2] = new Dog();
	arr[3] = new Cat();

	std::cout << "--------------------------------" << std::endl;

	for (int i = 0; i < 4; i++)
		arr[i]->makeSound();

	std::cout << "test copy--------------------------" << std::endl;

	Dog*	ddog = new Dog();
	Dog*	cpydog = new Dog(*ddog);

	std::cout << "--------------------------------" << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete (arr[i]);

	delete (ddog);
	delete (cpydog);

	return 0;
}