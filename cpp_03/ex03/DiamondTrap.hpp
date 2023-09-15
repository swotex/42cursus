/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:35 by njegat            #+#    #+#             */
/*   Updated: 2023/06/27 23:49:59 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &dia);
	DiamondTrap &operator = (const DiamondTrap &dia);
	void		whoAmI(void);
	~DiamondTrap();
	using	ScavTrap::attack;
private:
	DiamondTrap();
	std::string	name;
};

#endif
