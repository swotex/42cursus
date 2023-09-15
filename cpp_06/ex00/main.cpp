/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:31:10 by njegat            #+#    #+#             */
/*   Updated: 2023/08/24 13:10:08 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		for (int i=1; i<argc ; i++)
		{
			std::cout << "********** " << argv[i] << " **********" << std::endl;
			ScalarConverter::convert(std::string(argv[i]));
			std::cout << std::endl;
		}
	}
	
	else
	{

		std::cout << "--------------- " << "good test" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "e" << " **********" << std::endl;
		ScalarConverter::convert(std::string("e"));
		std::cout << std::endl;

		std::cout << "********** " << "-h" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-h"));
		std::cout << std::endl;

		std::cout << "********** " << "'h'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("'h'"));
		std::cout << std::endl;

		std::cout << "********** " << "'8'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("'8'"));
		std::cout << std::endl;

		std::cout << "********** " << "123" << " **********" << std::endl;
		ScalarConverter::convert(std::string("123"));
		std::cout << std::endl;

		std::cout << "********** " << "-640" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-640"));
		std::cout << std::endl;

		std::cout << "********** " << "45.7" << " **********" << std::endl;
		ScalarConverter::convert(std::string("45.7"));
		std::cout << std::endl;

		std::cout << "********** " << "-76.4" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-76.4"));
		std::cout << std::endl;

		std::cout << "********** " << "87.5f" << " **********" << std::endl;
		ScalarConverter::convert(std::string("87.5f"));
		std::cout << std::endl;

		std::cout << "********** " << "-98.2f" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-98.2f"));
		std::cout << std::endl;

		std::cout << "********** " << "0.346545554f" << " **********" << std::endl;
		ScalarConverter::convert(std::string("0.346545554f"));
		std::cout << std::endl;

		std::cout << "--------------- " << "Wrong char" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "'é'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("é"));
		std::cout << std::endl;

		std::cout << "********** " << "'hey'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("'hey'"));
		std::cout << std::endl;

		std::cout << "********** " << "-'a'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-'a'"));
		std::cout << std::endl;

		std::cout << "********** " << "'-a'" << " **********" << std::endl;
		ScalarConverter::convert(std::string("'-a'"));
		std::cout << std::endl;

		std::cout << "********** " << "''" << " **********" << std::endl;
		ScalarConverter::convert(std::string("''"));
		std::cout << std::endl;

		std::cout << "--------------- " << "Wrong int" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "+a" << " **********" << std::endl;
		ScalarConverter::convert(std::string("+a"));
		std::cout << std::endl;

		std::cout << "********** " << "é" << " **********" << std::endl;
		ScalarConverter::convert(std::string("é"));
		std::cout << std::endl;

		std::cout << "********** " << "234985249385798" << " **********" << std::endl;
		ScalarConverter::convert(std::string("234985249385798"));
		std::cout << std::endl;

		std::cout << "********** " << "-3456389645656" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-3456389645656"));
		std::cout << std::endl;

		std::cout << "********** " << "148a" << " **********" << std::endl;
		ScalarConverter::convert(std::string("148a"));
		std::cout << std::endl;

		std::cout << "--------------- " << "Wrong float" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "12.5.3f" << " **********" << std::endl;
		ScalarConverter::convert(std::string("12.5.3f"));
		std::cout << std::endl;

		std::cout << "********** " << "12.5ff" << " **********" << std::endl;
		ScalarConverter::convert(std::string("12.5ff"));
		std::cout << std::endl;

		std::cout << "********** " << ".47f" << " **********" << std::endl;
		ScalarConverter::convert(std::string(".47f"));
		std::cout << std::endl;

		std::cout << "********** " << "123f" << " **********" << std::endl;
		ScalarConverter::convert(std::string("123f"));
		std::cout << std::endl;

		std::cout << "********** " << "12.3r" << " **********" << std::endl;
		ScalarConverter::convert(std::string("12.3r"));
		std::cout << std::endl;

		std::cout << "********** " << "Overflow" << " **********" << std::endl;
		ScalarConverter::convert(std::string("9999999999999999999999999999999999999999.9999999999999999999999999999999999999999f"));
		std::cout << std::endl;

		std::cout << "--------------- " << "Wrong double" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "12.5.3" << " **********" << std::endl;
		ScalarConverter::convert(std::string("12.5.3"));
		std::cout << std::endl;

		std::cout << "********** " << ".47" << " **********" << std::endl;
		ScalarConverter::convert(std::string(".47"));
		std::cout << std::endl;

		std::cout << "********** " << "1." << " **********" << std::endl;
		ScalarConverter::convert(std::string("1."));
		std::cout << std::endl;

		std::cout << "********** " << "9999999999999999999999999999999999999999.9999999999999999999999999999999999999999" << " **********" << std::endl;
		ScalarConverter::convert(std::string("9999999999999999999999999999999999999999.9999999999999999999999999999999999999999"));
		std::cout << std::endl;

		std::cout << "********** " << "Overflow" << " **********" << std::endl;
		ScalarConverter::convert(std::string("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.99999999999999999999999999999"));
		std::cout << std::endl;

		std::cout << "--------------- " << "Other" << " ---------------" << std::endl << std::endl << std::endl;

		std::cout << "********** " << "+inf" << " **********" << std::endl;
		ScalarConverter::convert(std::string("+inf"));
		std::cout << std::endl;

		std::cout << "********** " << "+inff" << " **********" << std::endl;
		ScalarConverter::convert(std::string("+inff"));
		std::cout << std::endl;

		std::cout << "********** " << "-inf" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-inf"));
		std::cout << std::endl;

		std::cout << "********** " << "-inff" << " **********" << std::endl;
		ScalarConverter::convert(std::string("-inff"));
		std::cout << std::endl;

		std::cout << "********** " << "nan" << " **********" << std::endl;
		ScalarConverter::convert(std::string("nan"));
		std::cout << std::endl;

		std::cout << "********** " << "nanf" << " **********" << std::endl;
		ScalarConverter::convert(std::string("nanf"));
		std::cout << std::endl;
	}
	return 0;
}
