#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int	N = 5;
	Zombie*	horde = zombieHorde(N, "Zooooooo");
	while (--N >= 0)
		horde[N].announce();
	delete [] horde;
	return (0);
}
