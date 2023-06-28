/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:21:44 by njegat            #+#    #+#             */
/*   Updated: 2023/05/16 11:08:25 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# define ADD 5
# define SEARCH 6
# define EXIT 7

class PhoneBook
{
	public:
		int getChoice();
		void addContact();
		void printBook();
	private:
		Contact contactArr[8];
};

#endif