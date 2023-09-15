/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:05:05 by njegat            #+#    #+#             */
/*   Updated: 2023/06/30 14:47:35 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact(std::string info[5])
{
	this->fName = info[0];
	this->lName = info[1];
	this->nickName = info[2];
	this->number = info[3];
	this->darkestSecret = info[4];
}

std::string Contact::getFirstName()
{
	return (this->fName);
}

std::string Contact::getLastName()
{
	return (this->lName);
}

std::string Contact::getNickName()
{
	return (this->nickName);
}

void Contact::printContact()
{
	std::cout << "First name = " << this->fName << std::endl;
	std::cout << "Last name = " << this->lName << std::endl;
	std::cout << "Nickname = " << this->nickName << std::endl;
	std::cout << "Phone number = " << this->number << std::endl;
	std::cout << "Darkest secret = " << this->darkestSecret << std::endl;
}

bool Contact::isExist()
{
	if (this->fName.empty() == true)
		return (false);
	return (true);
}
