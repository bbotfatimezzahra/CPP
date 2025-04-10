#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	PhoneBook::add(void)
{
	this->conts[this->index % 8].fill();
	this->index++;
	std::cout << "V V V | Contact created | V V V" << std::endl;
}

void	PhoneBook::display(void)
{
	int	i;

	i = 0;
	this->conts[i].display(i);
	while (i < this->index && i < 8)
	{
		this->conts[i].display(i +  1);
		i++;
	}
	std::cout << "----------------------------\n";
}

void	PhoneBook::find(void)
{
	int	i;

	std::cout << "Please enter the index of the contact you want : ";
	std::cout << std::endl;
	std::cin >> i;
	if (i <= 0 || i > 8 || i > this->index)
		std::cout << "X X X | Out of range index | X X X" << std::endl;
	else
	{
		this->conts[i - 1].display();
		std::cout << "V V V | Contact found | V V V" << std::endl;
	}
}
