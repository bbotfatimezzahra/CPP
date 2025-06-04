#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat 🐱 Default Constructor" << std::endl;
	setType("Cat");
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat  🐱 Copy Constructor" << std::endl;
	_brain = new Brain(*copy.getBrain());
}

Cat::~Cat(void)
{
	std::cout << "Cat  🐱 Deconstructor" << std::endl;
	delete _brain;
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat  🐱 Assignement Operator" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);	
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}	
	return *this;
}

void	Cat::setBrain(const Brain &brain)
{
	delete _brain;
	_brain = new Brain(brain);
}

Brain	*Cat::getBrain(void) const
{
	return _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << " 🐱 MEOW MEOW 🐱 " << std::endl;
}
