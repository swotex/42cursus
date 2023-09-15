/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:30:22 by njegat            #+#    #+#             */
/*   Updated: 2023/08/21 08:51:16 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &cpy);
		Character &operator=(const Character &src);
		~Character();
		std::string const & getName() const;
		AMateria *getMateria(unsigned int pos);
		void setName(std::string name);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		AMateria *_inventory[4];
		std::string _name;
};

#endif
