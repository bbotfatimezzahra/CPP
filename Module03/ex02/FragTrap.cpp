#include "FragTrap.hpp"
#include <iostream>

//=============================DE / CONSTRUCTORS================================//

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Parameterised Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor called" << std::endl;
}

//=============================PUBLIC FUNCTIONS================================//

void	FragTrap::attack(const std::string & target)
{
	if (!_energyPoints)
		std::cout << "FragTrap "<< _name << " doesn't have enough energy points to attack!"<< std::endl;
	else
	{
		std::cout << "FragTrap "<< _name << " attacks " << target <<" ,causing "<< _attackDamage << " points of damage!"<< std::endl;
		_energyPoints--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says : LET'S HIGH FIVE GUYS" << std::endl;
}

