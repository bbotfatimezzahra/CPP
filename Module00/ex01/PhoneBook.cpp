#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

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

	std::cout << "Enter the index of the contact you want : " << std::endl;
	std::cin >> i;
	if (std::cin.eof())
	{
		std::cout << "X X X | Bad input | X X X" << std::endl;
		exit(0);
	}
	if (i <= 0 || i > 8 || i > this->_index)
	{
		std::cout << "X X X | Out of range index | X X X" << std::endl;
		std::cin.clear();
	}
	else
	{
		std::cout << "V V V | Contact found | V V V" << std::endl;
		this->_conts[i - 1].display();
		std::cout << "V V V | Contact found | V V V" << std::endl;
	}
	std::cin.ignore();
}
