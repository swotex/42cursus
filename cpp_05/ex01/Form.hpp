/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:12:14 by njegat            #+#    #+#             */
/*   Updated: 2023/08/18 05:49:17 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string name, int grade, int execute);
		Form(const Form &cpy);
		~Form();
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		std::string getName();
		bool getSigned();
		int getGrade();
		int getExecute();
		void beSigned(Bureaucrat &bureaucrat);
	private:
		Form &operator=(const Form &src);
		const std::string _name;
		bool _isSigned;
		const int _grade;
		const int _execute;
};
std::ostream &operator<<(std::ostream &os, Form &src);

#endif
