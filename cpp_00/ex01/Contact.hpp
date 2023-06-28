/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:45:53 by njegat            #+#    #+#             */
/*   Updated: 2023/05/16 14:45:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>

class Contact
{
	public:
		void setContact(std::string info[5]);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		void printContact();
		bool isExist();
	private:
		std::string fName;
		std::string lName;
		std::string nickName;
		std::string number;
		std::string darkestSecret;
};

#endif