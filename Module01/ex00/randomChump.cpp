#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name)
{
	Zombie	chump(name);
	chump.announce();
}
