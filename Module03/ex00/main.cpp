/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:52:54 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/03 16:18:18 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	Jack("Jack");
	
	/* Info */
	Jack.setAttackDamage(0);
	std::cout << "\n---------- ClapTrap Jack ----------" << std::endl;
	std::cout << "Hitpoints: " << Jack.getHitPoints() << " ";
	std::cout << "Energy: " << Jack.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Jack.getAttackDamage() << " ";
	std::cout << " Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Jack.attack("Sharks");
	Jack.attack("Pirates");
	Jack.takeDamage(20);
	Jack.takeDamage(4);
	Jack.beRepaired(10);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("Kings");

	std::cout << "\nFights are over..." << std::endl;
}
