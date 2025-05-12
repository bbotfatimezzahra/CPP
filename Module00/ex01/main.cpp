#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	std::string	cmd;
	PhoneBook	book;

	std::cout << "*** Welcome to the PhoneBook ***\n";
	while (1)
	{
		std::cout << "Please enter one of the following commands : \n";
		std::cout << "ADD : to add a new contact\n";
		std::cout << "SEARCH : to find a contact\n";
		std::cout << "EXIT : to quit the program" << std::endl;
		std::cin >> cmd;
		std::cin.ignore();
		if (!cmd.compare("ADD"))
			book.add();
		else if (!cmd.compare("SEARCH"))
		{
			book.display();
			book.find();
		}
		else if (!cmd.compare("EXIT"))
			break ;
		else
			std::cout << "X X X | Wrong command | X X X" << std::endl;
		std::cout << "==============================\n";
	}
	return (0);
}
