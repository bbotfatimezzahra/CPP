#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(std::string name ,std::string target) const
{
	AForm	*result = NULL;

	std::string	names[3 ] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
	AForm	*forms[3 ] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i=0; i < 3 ; i++)
	{
		if (!name.compare(names[i]))
			result = forms[i];
		else
			delete forms[i];
	}
	if (result)
		std::cout << "Intern Created " << name << std::endl;
	else
		std::cout << "There Is No Form Named " << name << std::endl;
	return result;
}
