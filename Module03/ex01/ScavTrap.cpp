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

//=============================OPERATOR OVERLOADING================================//

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Assignement operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs.getName();
		_hitPoints = rhs.getHitPoints();
		_energyPoints = rhs.getEnergyPoints();
		_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

//=============================PUBLIC FUNCTIONS================================//

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

