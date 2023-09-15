/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:17:09 by njegat            #+#    #+#             */
/*   Updated: 2023/08/16 02:45:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &cpy);
		MateriaSource &operator=(const MateriaSource &src);
		~MateriaSource();
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const &type);
	private:
		AMateria *_materia[4];
};

#endif
