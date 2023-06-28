/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:20:37 by njegat            #+#    #+#             */
/*   Updated: 2023/05/16 15:26:59 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int promptCompare(std::string input)
{
	if (input.compare("ADD") == 0)
		return (ADD);
	if (input.compare("SEARCH") == 0)
		return (SEARCH);
	if (input.compare("EXIT") == 0)
		return (EXIT);
	else
		return (0);
}

int PhoneBook::getChoice()
{
	std::string input;

	std::cout << "Make youre choice, ADD, SEARCH, EXIT :" << std::endl;
	std::cin >> input;
	while (promptCompare(input) == 0)
	{
		std::cout << std::endl << "Bad entry, retry :" << std::endl;
		std::cin >> input;
	}
	std::cout << std::endl;
	return (promptCompare(input));
}

void PhoneBook::addContact()
{
	static int pos = 0;
	Contact tmp;
	std::string input[5];
	std::string display[5] = {"Enter the first name : ",
								"Enter the last name : ",
								"Enter the nickname : ",
								"Enter the phone number : ",
								"Enter the darkest secret : "};

	for (int i = 0; i<5; i++)
	{
		std::cout << display[i];
		std::cin >> input[i];
		std::cout << std::endl;
	}
	tmp.setContact(input);
	this->contactArr[pos] = tmp;
	pos++;
	pos = pos % 8;
}

static void printContact(Contact cont)
{
	if (cont.isExist() == true)
		cont.printContact();
	else
		std::cout << "This contact not exist" << std::endl;
}

static std::string getFirstTen(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

static void displayChoice(Contact contacts[8])
{
	for (int i=0; i < 8; i++)
	{
		if (contacts[i].isExist() == false)
			break;
		std::cout << i + 1 << std::setw(10) << "|" << std::setw(10) << std::flush;
		std::cout << getFirstTen(contacts[i].getFirstName()) << std::setw(10) << "|" << std::setw(10) << std::flush;
		std::cout << getFirstTen(contacts[i].getLastName()) << std::setw(10) << "|" << std::setw(10) << std::flush;
		std::cout << getFirstTen(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::printBook()
{
	std::string input;
	
	displayChoice(this->contactArr);
	std::cout << "choice your contact 1 - 8, or all :" << std::endl;
	std::cin >> input;
	std::cout << std::endl;
	if (input.compare("1") == 0)
		printContact(this->contactArr[0]);
	else if (input.compare("2") == 0)
		printContact(this->contactArr[1]);
	else if (input.compare("3") == 0)
		printContact(this->contactArr[2]);
	else if (input.compare("4") == 0)
		printContact(this->contactArr[3]);
	else if (input.compare("5") == 0)
		printContact(this->contactArr[4]);
	else if (input.compare("6") == 0)
		printContact(this->contactArr[5]);
	else if (input.compare("7") == 0)
		printContact(this->contactArr[6]);
	else if (input.compare("8") == 0)
		printContact(this->contactArr[7]);
	else if (input.compare("all") == 0)
	{
		for (int i=0; i < 8; i++)
		{
			if (this->contactArr[i].isExist() == false)
				break;
			std::cout << " - Contact " << i + 1 << std::endl;
			this->contactArr[i].printContact();
			std::cout << std::endl;
		}
	}
	else
		std::cout << "bad entry" << std::endl;
	std::cout << std::endl;
}
