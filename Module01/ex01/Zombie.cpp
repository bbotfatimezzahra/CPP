#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": DEAD" << std::endl;
}

void	Zombie::set_name(std::string name)
{ 
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

