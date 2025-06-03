#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("default")
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal Deconstructor" << std::endl;
}

Animal & Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal Assignement Operator" << std::endl;
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

std::string	Animal::getType(void) const
{
	return _type;
}

void	Animal::setType(const std::string &type)
{
	_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal Sound" << std::endl;
}
