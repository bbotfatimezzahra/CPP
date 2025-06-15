#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy)
{
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " Has Been Pardoned By ZAPHOD BEEBLEBROX" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
	out << "PresidentialPardonForm : {" << obj.getName() << "} Signature grade : {" << obj.getSignGrade() << "} Execution grade : {" << obj.getExecuteGrade() << "} Target : {" << obj.getTarget() << "} Status : {" << ((obj.getStatus())? "SIGNED}" : "NOT SIGNED}") << std::endl;
	return out;
}
