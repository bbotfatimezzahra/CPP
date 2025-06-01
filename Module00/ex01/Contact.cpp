#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	is_valid_num(std::string str)
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	while (a && str[i])
	{
		a = std::isdigit(static_cast<unsigned char>(str[i]));
		i++;
	}
	return (a);
}

bool	is_valid_str(std::string str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (!a && str[i])
	{
		a = std::isalnum(static_cast<unsigned char>(str[i]));
		i++;
	}
	return (a);
}

std::string	get_input(std::string str, int type)
{
	std::string	input;
	bool	valid;

	std::cout.flush();
	valid = 0;
	do
	{
		std::cout << str << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << "X X X | Bad Input | X X X" << std::endl;
			exit(0);
		}
		if (input.empty())
			std::cout << "X X X | Empty Input | X X X" << std::endl;
		else if (!type && !is_valid_str(input))
			std::cout << "X X X | Invalid Input | X X X" << std::endl;
		else if (type && !is_valid_num(input))
			std::cout << "X X X | Input Not Number | X X X" << std::endl;
		else
			valid = 1;
	} while (!valid);
	return (input);
}

void	Contact::fill(void)
{
	std::cout << "* Adding a new contact *\n";
	this->_first_name = get_input("Enter first name :", 0);
	this->_last_name = get_input("Enter last name :", 0);
	this->_nickname = get_input("Enter nickname :", 0);
	this->_phone_number = get_input("Enter phone number :", 1);
	this->_darkest_secret = get_input("Enter darkest secret :", 0);
}

void	truncate(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str;
}

void	Contact::display(void) const
{
	std::cout << "First name :" << this->_first_name << std::endl;
	std::cout << "Last name :" << this->_last_name << std::endl;
	std::cout << "Nickname :" << this->_nickname << std::endl;
	std::cout << "Phone number :" << this->_phone_number << std::endl;
	std::cout << "Darkest secret :" << this->_darkest_secret << std::endl;
}

void	Contact::display(int index) const
{
	if (!index)
	{
		truncate("index");
		std::cout << "|";
		truncate("first_name");
		std::cout << "|";
		truncate("last_name");
		std::cout << "|";
		truncate("nickname");
		std::cout << "|" << std::endl;
		return ;
	}
	std::cout << "         " << index << "|";
	truncate(this->_first_name);
	std::cout << "|";
	truncate(this->_last_name);
	std::cout << "|";
	truncate(this->_nickname);
	std::cout << "|" << std::endl;
}
