/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:11:58 by njegat            #+#    #+#             */
/*   Updated: 2023/05/16 10:59:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	int choice = 0;
	
	PhoneBook book;
	while (1)
	{
		choice = book.getChoice();
		if (choice == ADD)
			book.addContact();
		if (choice == SEARCH)
			book.printBook();
		if (choice == EXIT)
			break;
	}
	std::cout << "Bye" << std::endl;
	return 0;
}
