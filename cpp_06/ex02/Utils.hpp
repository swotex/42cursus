/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:29:30 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 14:57:05 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>

class Utils
{
	public:
		static Base *generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
	private:
		Utils();
		Utils(const Utils &cpy);
		Utils &operator=(const Utils &src);
		~Utils();
};

#endif
