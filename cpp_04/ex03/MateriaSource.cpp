/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:35:09 by njegat            #+#    #+#             */
/*   Updated: 2023/08/22 08:31:43 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i=0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	for (int i=0; i < 4; i++)
		_materia[i] = cpy._materia[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	for (int i=0; i < 4; i++)
	{
		if (_materia[i])
		{
			delete (_materia[i]);
			_materia[i] = NULL;
		}
	}
	for (int i=0; i < 4; i++)
	{
		if (src._materia[i])
			_materia[i] = src._materia[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i=0; i < 4; i++)
	{
		if (_materia[i])
			delete (_materia[i]);
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i=0; i < 4; i++)
	{
		if (_materia[i] == materia)
		{
			std::cout << "Materia already learn" << std::endl;
			return ;
		}
	}
	for (int i=0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = materia;
			return ;
		}
	}
	std::cout << "This MateriaSource is full" << std::endl;
	delete (materia);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i=0; i < 4; i++)
	{
		if (_materia[i])
		{
			if(_materia[i]->getType().compare(type) == 0)
				return (_materia[i]->clone());
		}
	}
	return (NULL);
	std::cout << "This materia has not been learned" << std::endl;
}
