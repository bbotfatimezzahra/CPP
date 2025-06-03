/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:52:54 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 21:52:57 by fbbot            ###   ########.fr       */
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
	for (int i = 0; i < 20; i++)
		Jack.attack("Pirates");
	Jack.takeDamage(4);
	Jack.beRepaired(10);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("Kings");

	std::cout << "\nFights are over..." << std::endl;
}
