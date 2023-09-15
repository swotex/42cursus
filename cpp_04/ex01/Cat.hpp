/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:07:33 by njegat            #+#    #+#             */
/*   Updated: 2023/08/22 08:10:15 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &ct);
	Cat	&operator=(const Cat &ct);
	void	makeSound(void) const;
	~Cat();
private:
	Brain	*brain;
};

#endif
