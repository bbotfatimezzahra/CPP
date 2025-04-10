#pragma once
#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	private :
		Contact	conts[8];
		int	index;
	public :
		PhoneBook();
		void	add(void);
		void	display(void);
		void	find(void);
};
