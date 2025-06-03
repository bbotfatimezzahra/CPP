#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain::~Brain()
{
}

Brain & Brain::operator=(const Brain &rhs)
{
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
