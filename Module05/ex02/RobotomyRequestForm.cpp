#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	// std::srand(std::time(NULL));//ask later
	std::cout << "DRILLING NOOIIISE " << std::endl;
	if (std::time(NULL) % 2 == 0)
		std::cout << _target << " is Robotomized Successfully" << std::endl;
	else
		std::cout << _target << "Robotomization Failed " << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
	out << "RobotomyRequestForm : {" << obj.getName() << "} Signature grade : {" << obj.getSignGrade() << "} Execution grade : {" << obj.getExecuteGrade() << "} Target : {" << obj.getTarget() << "} Status : {" << ((obj.getStatus())? "SIGNED}" : "NOT SIGNED}") << std::endl;
	return out;
}
