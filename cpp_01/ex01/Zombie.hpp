/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:51:06 by njegat            #+#    #+#             */
/*   Updated: 2023/06/06 05:08:26 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
public:
	void	announce(void);
	void	setName(std::string name);
	Zombie(std::string newName);
	Zombie(void);
	~Zombie(void);
private:
	std::string	name;
};

#endif
