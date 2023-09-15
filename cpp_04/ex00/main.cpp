/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:57:41 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 05:55:54 by njegat           ###   ########.fr       */
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
	return 0;
}