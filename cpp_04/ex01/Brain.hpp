/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:24:55 by njegat            #+#    #+#             */
/*   Updated: 2023/06/28 07:27:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &cpy);
	Brain		&operator=(const Brain &br);
	std::string	getIdeaId(int id);
	void		setIdeaId(int id, std::string idea);
	~Brain();
private:
	std::string ideas[100];
};

#endif
