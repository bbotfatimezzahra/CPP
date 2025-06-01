/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:06:08 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:08:04 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

void	error(std::string str)
{
	std::cerr << str;
	exit(1);
}

void	sed(char *file, std::string s1, std::string s2)
{
	std::ifstream	og(file);
	if (!og)
		error("Error while openning files\n");
	std::ofstream nfile(strcat(file, ".replace"));
	if (!nfile)
	{
		og.close();
		error("Error while openning files\n");
	}

	std::string	line;
	std::string::size_type	p;

	std::getline(og, line, '\0');
	p = line.find(s1);
	while (p != std::string::npos)
	{
		line.erase(p, s1.length());
		line.insert(p, s2);
		p = line.find(s1, p + s2.length());
	}
	nfile << line;
	og.close();
	nfile.close();
}

int	main(int ac, char *av[])
{
	if (ac != 4)
		error("Usage : ./Sed2.0 filename string1 string2\n");

	std::string	file = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (file.empty() || s1.empty() || s2.empty())
		error("No Empty arguments\n");
	sed(av[1], s1, s2);
	return (0);
}
