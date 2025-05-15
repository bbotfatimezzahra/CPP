#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug(void)
{
	std::cout << "**DEBUG** I love extra cheese for my 7XL burger." << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "**INFO** I cannot believe extra cheese costs more money." << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "**WARNING** I think I deserve some extra cheese for free." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "**ERROR** This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	hfunc	message[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[] = {"debug", "info", "warning", "error"};
	int	i = 0;
	
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*message[i])();
}
