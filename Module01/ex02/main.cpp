/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:01:16 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:01:23 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "-> address of the string: " << &str << std::endl;
	std::cout << "-> address of stringPTR: " << stringPTR << std::endl;
	std::cout << "-> address of stringREF : " << &stringREF << std::endl;
	std::cout << "<---------------------------------------->\n";
	std::cout << "-> value of the string : " << str << std::endl;
	std::cout << "-> value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "-> value pointed to by stringREF : " << stringREF << std::endl;
	return (0);
}
