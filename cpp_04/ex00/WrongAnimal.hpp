/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:58:52 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 05:05:44 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal &an);
	WrongAnimal &operator=(const WrongAnimal &an);
	std::string	getType(void) const;
	void		makeSound(void) const;
	~WrongAnimal();
protected:
	std::string	type;
};

#endif
