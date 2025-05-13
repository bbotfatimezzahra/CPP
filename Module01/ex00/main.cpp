#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie *one = newZombie("frank");
	one->announce();
	randomChump("CHump");
	delete one;
	return (0);
}
