/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:58:52 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 07:02:04 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
public:
	Animal();
	Animal(std::string name);
	Animal(const Animal &an);
	Animal			&operator=(const Animal &an);
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
	virtual ~Animal();
protected:
	std::string	type;
};

#endif
