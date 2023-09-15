/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 06:22:30 by njegat            #+#    #+#             */
/*   Updated: 2023/07/22 17:14:22 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int	replace(char **argv)
{
	std::ifstream	ifile(argv[1]);
	std::string		line;

	if (ifile.is_open())
	{
		std::string tmp(argv[1]);
		tmp.append(".replace");
		std::ofstream	ofile(tmp.c_str());
		if (ofile.is_open())
		{
			while (std::getline(ifile, line))
			{
				if (line.find(argv[2]) != std::string::npos)
				{
					for (unsigned int i=0; line[i]; i++)
					{
						if (i == line.find(argv[2], i) && \
							line.find(argv[2], i) != std::string::npos)
						{
							ofile << argv[3];
							i += std::string(argv[2]).size() - 1;
						}
						else
							ofile << line[i];
					}
					ofile << std::endl;
				}
				else
					ofile << line << std::endl;
			}
		}
		else
		{
			ifile.close();
			return (1);
		}
		ifile.close();
	}
	else
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	if (argv[2][0] == 0 || argv[3][0] == 0)
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	if (replace(argv))
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	return 0;
}
