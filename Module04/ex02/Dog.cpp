#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog Default Constructor" << std::endl;
	setType("Dog");
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Deconstructor" << std::endl;
	delete _brain;
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assignement Operator" << std::endl;
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);	
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

void	Dog::setBrain(const Brain &brain)
{
	delete _brain;
	_brain = new Brain(brain);
}

Brain	*Dog::getBrain(void) const
{
	return _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK BARK" << std::endl;
}
