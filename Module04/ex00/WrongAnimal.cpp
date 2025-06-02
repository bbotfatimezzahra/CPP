#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("default")
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Deconstructor" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal Assignement Operator" << std::endl;
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}
