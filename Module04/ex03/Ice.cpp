#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return *this;
}

Ice *Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
