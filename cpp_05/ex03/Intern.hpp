/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 06:42:59 by njegat            #+#    #+#             */
/*   Updated: 2023/08/21 13:50:44 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &src);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
		AForm *makeShrubbery(std::string name, std::string target);
		AForm *makeRobotomy(std::string name, std::string target);
		AForm *makePresidential(std::string name, std::string target);
		class FormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
