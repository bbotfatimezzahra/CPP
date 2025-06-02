#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	Diamond("Daniel");
	DiamondTrap	Dia;

	Dia = Diamond;
	Dia.whoAmI();
	std::cout << Dia.getHitPoints() << Dia.getEnergyPoints() <<Dia.getAttackDamage()<< std::endl;
	Diamond.attack("Pirates");
	Diamond.attack("Kings");
	Diamond.attack("Lions");
	Diamond.beRepaired(10);
	Diamond.takeDamage(100);
	Diamond.guardGate();
	Diamond.highFivesGuys();
	Diamond.whoAmI();
}
