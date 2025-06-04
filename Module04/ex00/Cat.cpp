#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat 🐱 Default Constructor" << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat 🐱 Copy Constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat 🐱 Deconstructor" << std::endl;
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat 🐱 Assignement Operator" << std::endl;
	Animal::operator=(rhs);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "🐱 MEOW MEOW 🐱" << std::endl;
}
