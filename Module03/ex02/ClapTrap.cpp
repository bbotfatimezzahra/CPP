#include "ClapTrap.hpp"
#include <iostream>

//=============================DE / CONSTRUCTORS================================//

ClapTrap::ClapTrap() : _name("random"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Parameterised Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor called" << std::endl;
}

//=============================SE / GETTERS================================//

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int	ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

void	ClapTrap::setName(std::string name)
{
	 _name = name;
}

void	ClapTrap::setHitPoints(int hit)
{
	 _hitPoints = hit;
}

void	ClapTrap::setEnergyPoints(int energy)
{
	 _energyPoints = energy;
}

void	ClapTrap::setAttackDamage(int attack)
{
	 _attackDamage = attack;
}

//=============================OPERATOR OVERLOADING================================//

ClapTrap & ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Assignement operator called" << std::endl;
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

void	ClapTrap::attack(const std::string & target)
{
	if (!_energyPoints)
		std::cout << "ClapTrap "<< _name << " doesn't have enough energy points to attack!"<< std::endl;
	else
	{
		std::cout << "ClapTrap "<< _name << " attacks " << target <<" ,causing "<< _attackDamage << " points of damage!"<< std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap "<< _name << "is Already dead"<< std::endl;
	else
	{
		std::cout << "ClapTrap "<< _name << " took " << amount << " points of damage!"<< std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints)
		std::cout << "ClapTrap "<< _name << " doesn't have enough points to repair!"<< std::endl;
	else
	{
		std::cout << "ClapTrap "<< _name << " got repaired by " << amount << " hit points!"<< std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}
