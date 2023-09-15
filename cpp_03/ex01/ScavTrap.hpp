/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:11:20 by njegat            #+#    #+#             */
/*   Updated: 2023/06/25 16:07:39 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scav);
	ScavTrap	&operator = (const ScavTrap &scav);
	void		guardGate(void);
	void		attack(const std::string &target);
	~ScavTrap();
private:
	ScavTrap();
};

#endif
