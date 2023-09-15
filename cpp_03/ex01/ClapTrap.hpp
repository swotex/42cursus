/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:55:52 by njegat            #+#    #+#             */
/*   Updated: 2023/06/25 15:19:58 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap);
	ClapTrap	&operator = (const ClapTrap &clap);
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName(void);
	~ClapTrap();

protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

private:
	ClapTrap();
};

#endif
