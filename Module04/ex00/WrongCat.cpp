#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Deconstructor" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat Assignement Operator" << std::endl;
	WrongAnimal::operator=(rhs);
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WRONG MEOW MEOW" << std::endl;
}
