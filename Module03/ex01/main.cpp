/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:54:50 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/03 16:19:11 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	temp("Daniel");
	ScavTrap	Daniel(temp);

	/* Assignment check */
	temp.setAttackDamage(55);

	/* Info */
	std::cout << "\n---------- ScavTrap Daniel ----------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHitPoints() << " ";
	std::cout << "Energy: " << Daniel.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Daniel.getAttackDamage() << " ";
	std::cout << "Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(14);
	Daniel.beRepaired(10);
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Lions");
	Daniel.attack("Kings");

	std::cout << "\nFights are over. Guarding time...\n" << std::endl;
	Daniel.guardGate();
	std::cout << "\nGuareded too much...Enough!\n" << std::endl;
}
