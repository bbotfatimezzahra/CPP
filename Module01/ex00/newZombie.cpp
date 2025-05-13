#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
