/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:44:07 by njegat            #+#    #+#             */
/*   Updated: 2023/08/21 12:28:32 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	src->learnMateria(ice);
	src->learnMateria(new Cure());
	src->learnMateria(ice);
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // full

	Character* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); // full

	Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(12, *bob); // out of range
	tmp = me->getMateria(1);
	me->unequip(1);
	delete tmp;
	me->unequip(1); // unequip empty location
	me->use(1, *bob); // use empty materia

	*bob = *me;
	bob->use(2, *me);
	bob->use(1, *me);

	delete bob;
	delete me;
	delete src;
	
	return 0;
}