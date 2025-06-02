#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap	temp("Daniel");
	FragTrap	Daniel("No name");

	/* Assignment check */
	temp.setAttackDamage(55);
	Daniel = temp;

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

	std::cout << "\nFights are over. High Fives time...\n" << std::endl;
	Daniel.highFivesGuys();
	std::cout << "\n...Enough ...!\n" << std::endl;
}
