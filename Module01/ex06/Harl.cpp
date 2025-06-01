/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:15:07 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:16:24 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]\n I love extra cheese for my 7XL burger.\n" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]\n I cannot believe extra cheese costs more money.\n" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]\n I think I deserve some extra cheese for free.\n" << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]\n This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	
	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break;
		case 1:
			this->_info();
			this->_warning();
			this->_error();
			break;
		case 2:
			this->_warning();
			this->_error();
			break;
		case 3:
			this->_error();
			break;
		default:
			std::cout <<"[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	}
}
