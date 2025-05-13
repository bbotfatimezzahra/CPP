#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	while (--N >= 0)
		horde[N].set_name(name);
	return(horde);
}
