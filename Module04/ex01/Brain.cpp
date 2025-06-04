#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain 🧠 Default Constructor" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain  🧠 Copy Constructor" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain  🧠 DeConstructor" << std::endl;
}

Brain & Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain  🧠 Assignement Operator" << std::endl;
	if (this != &rhs)
	{
		for(int i=0; i < 100; i++)
			_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

std::string	Brain::getIdea(int i) const
{
	return _ideas[i];
}

void	Brain::setIdea(int i, const std::string &idea)
{
	_ideas[i] = idea;
}
