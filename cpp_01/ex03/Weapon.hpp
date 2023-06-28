/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:38:24 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 06:14:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
public:
	const std::string	&getType(void);
	void				setType(std::string type);
	Weapon(std::string type);
	~Weapon();
private:
	std::string type;
};

#endif
