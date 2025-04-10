#include "Contact.hpp"

void	Contact::fill(void)
{
	std::cout << "* Adding a new contact *\n";
	std::cout << "Enter first name :" << std::endl;
	std::getline(std::cin >> std::ws, this->first_name);
	std::cout << "Enter last name :" << std::endl;
	std::getline(std::cin >> std::ws, this->last_name);
	std::cout << "Enter nickname :" << std::endl;
	std::getline(std::cin >> std::ws, this->nickname);
	std::cout << "Enter phone number :" << std::endl;
	std::getline(std::cin >> std::ws, this->phone_number);
	std::cout << "Enter darkest secret :" << std::endl;
	std::getline(std::cin >> std::ws, this->darkest_secret);
}

void	Contact::display(void)
{
	std::cout << "First name :" << this->first_name << std::endl;
	std::cout << "Last name :" << this->last_name << std::endl;
	std::cout << "Nickname :" << this->nickname << std::endl;
	std::cout << "Phone number :" << this->phone_number << std::endl;
	std::cout << "Darkest secret :" << this->darkest_secret << std::endl;
}

void	truncate(std::string str)
{
	int	i;
	std::string	print;

	i = 10 - str.length();
	while (i > 0)
	{
		std::cout << " ";
		i--;
	}
	if (i < 0)
		str = str.substr(0, 9);
	std::cout << str;
	if (i < 0)
		std::cout << ".";
}
		
void	Contact::display(int index)
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
	truncate(this->first_name);
	std::cout << "|";
	truncate(this->last_name);
	std::cout << "|";
	truncate(this->nickname);
	std::cout << "|" << std::endl;
}
