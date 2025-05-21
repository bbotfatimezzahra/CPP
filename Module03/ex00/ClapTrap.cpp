#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("random"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterised Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &rhs)
{

}

void	ClapTrap::attack(const std::string & target)
{
}

void	ClapTrap::takeDamage(unsigned int amount)
{
}

void	ClapTrap::beRepaired(unsigned int amount)
{
}

