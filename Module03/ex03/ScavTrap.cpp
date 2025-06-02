#include "ScavTrap.hpp"
#include <iostream>

//=============================DE / CONSTRUCTORS================================//

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parameterised Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}

//=============================PUBLIC FUNCTIONS================================//

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

void	ScavTrap::attack(const std::string & target)
{
	if (!_energyPoints)
		std::cout << "ScavTrap "<< _name << " doesn't have enough energy points to attack!"<< std::endl;
	else
	{
		std::cout << "ScavTrap "<< _name << " attacks " << target <<" ,causing "<< _attackDamage << " points of damage!"<< std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in GATE KEEPER Mode" << std::endl;
}

