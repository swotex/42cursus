/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:14 by njegat            #+#    #+#             */
/*   Updated: 2023/08/30 13:26:51 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <iostream>
# define DATAFILE "data.csv"

class Error
{
	public:
		class NameFileException : public std::exception
		{
			const char *what() const throw();
		};
		class OpenDataException : public std::exception
		{
			const char *what() const throw();
		};
		class FatalErrorException : public std::exception
		{
			const char *what() const throw();
		};
		class ErrorDataFormat : public std::exception
		{
			const char *what() const throw();
		};
		class OpenInfileException : public std::exception
		{
			const char *what() const throw();
		};
};

class BitcoinExchange : public Error
{
	public:
		BitcoinExchange(std::string infile);
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		void execute();
		
	private:
		void cpyData();
		BitcoinExchange();
		std::map<std::string, float> _data;
		std::string _infile;
};


#endif
