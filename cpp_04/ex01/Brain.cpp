/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:24:51 by njegat            #+#    #+#             */
/*   Updated: 2023/06/29 09:55:35 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is created." << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	std::cout << "Brain is created by copy." << std::endl;
}

Brain		&Brain::operator=(const Brain &br)
{
	if (this == &br)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = br.ideas[i];
	return (*this);
}

std::string	Brain::getIdeaId(int id)
{
	if (id < 0 || id >= 100)
		return (NULL);
	return (ideas[id]);
}

void		Brain::setIdeaId(int id, std::string idea)
{
	if (id <= 0 && id < 100)
		ideas[id] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain is deleted." << std::endl;
}
