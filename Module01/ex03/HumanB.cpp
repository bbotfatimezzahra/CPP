#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << "attacks with ";
	if (this->_weapon)
		std::cout <<"their " << this->_weapon->getType() << std::endl;
	else
		std::cout << "no weapon" << std::endl;
}
