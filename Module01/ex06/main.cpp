#include "Harl.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	Harl	harl;
	std::string	level;

	if (ac == 1)
		std::cout << "[ That's weird you're not complaining ]\n" << std::endl;
	else if (ac >= 2)
	{
		level = av[1];
		harl.complain(level);
	}
	return (0);
}
