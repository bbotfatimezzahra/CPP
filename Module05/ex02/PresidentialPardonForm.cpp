#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): _signGrade(0), _executeGrade(0)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	_status = false;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		_status = rhs.getStatus();
	return *this;
}

std::string	PresidentialPardonForm::getName(void) const
{
	return _name;
}

int	PresidentialPardonForm::getSignGrade(void) const
{
	return _signGrade;
}

int	PresidentialPardonForm::getExecuteGrade(void) const
{
	return _executeGrade;
}

bool	PresidentialPardonForm::getStatus(void) const
{
	return _status;
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_status = true;
}

virtual PresidentialPardonForm::execute(const Bureaucrat &executor)
{
	if (executer.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char * PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}
const char * PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
	out << "PresidentialPardonForm : " << obj.getName() << " Signature grade : " << obj.getSignGrade() << " Execution grade : " << obj.getExecuteGrade() << " Status : " << ((obj.getStatus())? "SIGNED" : "NOT SIGNED")<< std::endl;
	return out;
}
