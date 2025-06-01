/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:10:49 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:13:54 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;
	std::string	level;

	do
	{
		std::cout << "==> enter a level (DEBUG - INFO - WARNING - ERROR ) or EXIT <==" << std::endl;
		std::cin >> level;
		harl.complain(level);
	}
	while (level.compare("EXIT"));
	return (0);
}
