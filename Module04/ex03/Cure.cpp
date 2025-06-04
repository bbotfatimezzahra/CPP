#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{ 
	this->_type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &rhs)
{
	(void)rhs;
	return *this;
}

Cure *Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
