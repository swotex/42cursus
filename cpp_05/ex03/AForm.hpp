/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:12:14 by njegat            #+#    #+#             */
/*   Updated: 2023/08/20 06:27:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string name, int grade, int execute);
		AForm(const AForm &cpy);
		virtual ~AForm();
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
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		std::string getName();
		bool getSigned() const;
		int getGrade() const;
		std::string getName() const;
		int getExecute();
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
	private:
		AForm &operator=(const AForm &src);
		const std::string _name;
		bool _isSigned;
		const int _grade;
		const int _execute;
};
std::ostream &operator<<(std::ostream &os, AForm &src);

#endif
