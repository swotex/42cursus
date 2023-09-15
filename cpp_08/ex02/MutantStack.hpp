/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:57:28 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 20:06:36 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T, class cont=std::deque<T> >
class MutantStack : public std::stack<T, cont>
{
	public:
		MutantStack(){};
		MutantStack(const MutantStack &cpy) : std::stack<T, cont>(cpy){};
		MutantStack &operator=(const MutantStack &src)
		{
			if (this == &src)
				return (*this);
			std::stack<T, cont>::operator=(src);
			return (*this);
		};
		~MutantStack(){};

		typedef typename std::stack<T, cont>::container_type::iterator iterator;
		typedef typename std::stack<T, cont>::container_type::const_iterator const_iterator;
		
		iterator begin(){return (this->c.begin());};
		iterator end(){return (this->c.end());};
		const_iterator begin() const {return (this->c.begin());};
		const_iterator end() const {return (this->c.end());};

};

#endif
