/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:43:51 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 03:51:15 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &cpy);
		Ice &operator=(const Ice &src);
		void use(ICharacter &character);
		AMateria* clone() const;
		~Ice();
};

#endif
