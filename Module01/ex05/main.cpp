#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;
	std::string	level;

	do
	{
		std::cout << "==> enter a level or exit <==" << std::endl;
		std::cin >> level;
		harl.complain(level);
	}
	while (level.compare("exit"));
	return (0);
}
