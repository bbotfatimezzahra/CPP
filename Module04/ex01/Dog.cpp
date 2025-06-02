#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog Default Constructor" << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Deconstructor" << std::endl;
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assignement Operator" << std::endl;
	Animal::operator=(rhs);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK BARK" << std::endl;
}
