#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}


void	PhoneBook::add(void)
{
	this->_conts[this->_index % 8].fill();
	this->_index++;
	std::cout << "V V V | Contact created | V V V" << std::endl;
}

void	PhoneBook::display(void) const
{
	int	i;

	i = 0;
	this->_conts[i].display(i);
	while (i < this->_index && i < 8)
	{
		this->_conts[i].display(i +  1);
		i++;
	}
	std::cout << "----------------------------\n";
}

void	PhoneBook::find(void) const
{
	int	i;
	bool	valid;

	valid = 0;
	do
	{
		std::cout << "Enter the index of the contact you want : ";
		std::cout << std::endl;
		std::cin >> i;
		if (!std::cin.good() || i <= 0 || i > 8 || i > this->_index)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "X X X | Out of range index | X X X" << std::endl;
			if (!this->_index)
				break;
		}
		else
		{
			std::cout << "V V V | Contact found | V V V" << std::endl;
			this->_conts[i - 1].display();
			std::cout << "V V V | Contact found | V V V" << std::endl;
			valid = 1;
		}
	} while (!valid);
}
