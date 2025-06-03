#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("default")
{
	std::cout << "AAnimal Default Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal Copy Constructor" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Deconstructor" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "AAnimal Assignement Operator" << std::endl;
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return _type;
}

void	AAnimal::setType(const std::string &type)
{
	_type = type;
}
