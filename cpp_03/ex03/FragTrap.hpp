/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:02:48 by njegat            #+#    #+#             */
/*   Updated: 2023/06/27 23:45:01 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag);
	FragTrap	&operator = (const FragTrap &frag);
	void		highFivesGuys(void);
	~FragTrap();
private:
	FragTrap();
};

#endif
