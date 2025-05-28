#include "DiamondTrap.hpp"
#include <iostream>

//=============================DE / CONSTRUCTORS================================//

DiamondTrap::DiamondTrap(): ClapTrap("Rando_clap_name"), _name("Rando") 
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << "DiamondTrap Parameterised Constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), _name(copy.getName())
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor called" << std::endl;
}

//=============================PUBLIC FUNCTIONS================================//

std::string	DiamondTrap::getName(void) const
{
	return _name;
}

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap says : my name is [" << _name << "] and my Clap name is [" << ClapTrap::_name << "]" << std::endl;
}

