#include "AForm.hpp"
#include <iostream>

AForm::AForm(): _signGrade(0), _executeGrade(0)
{
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	*this = copy;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	_status = false;
}

AForm::~AForm()
{}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_status = rhs.getStatus();
	return *this;
}

std::string	AForm::getName(void) const
{
	return _name;
}

int	AForm::getSignGrade(void) const
{
	return _signGrade;
}

int	AForm::getExecuteGrade(void) const
{
	return _executeGrade;
}

bool	AForm::getStatus(void) const
{
	return _status;
}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_status = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_status)
		throw NotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char * AForm::NotSignedException::what() const throw()
{
	return "Form Not Signed!";
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << "AForm : " << obj.getName() << " Signature grade : " << obj.getSignGrade() << " Execution grade : " << obj.getExecuteGrade() << " Status : " << ((obj.getStatus())? "SIGNED" : "NOT SIGNED")<< std::endl;
	return out;
}
