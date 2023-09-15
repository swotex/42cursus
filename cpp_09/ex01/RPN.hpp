/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:28:58 by njegat            #+#    #+#             */
/*   Updated: 2023/09/06 22:10:21 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
	public:
		RPN(std::string line);
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &src);
		~RPN();
		void resolve();
	private:
		std::string _line;
		RPN();
};

#endif
