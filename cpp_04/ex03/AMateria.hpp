/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:50:09 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 03:42:00 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &cpy);
		AMateria &operator=(const AMateria &src);
		virtual ~AMateria();
		void setType(std::string type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	private:
		AMateria();
};

#endif
