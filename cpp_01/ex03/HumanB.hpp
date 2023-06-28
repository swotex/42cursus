/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 06:03:41 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 06:07:15 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	void	attack(void);
	void	setWeapon(Weapon &weapon);
	~HumanB();
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
