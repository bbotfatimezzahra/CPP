#include "Form.hpp"
#include <iostream>

Form::Form(): _signGrade(0), _executeGrade(0)
{
}

Form::Form(const Form &copy): _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	*this = copy;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	_status = false;
}

Form::~Form()
{}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_status = rhs.getStatus();
	return *this;
}

std::string	Form::getName(void) const
{
	return _name;
}

int	Form::getSignGrade(void) const
{
	return _signGrade;
}

int	Form::getExecuteGrade(void) const
{
	return _executeGrade;
}

bool	Form::getStatus(void) const
{
	return _status;
}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_status = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

std::ostream	&operator<<(std::ostream &out, const Form &obj)
{
	out << "Form : " << obj.getName() << " Signature grade : " << obj.getSignGrade() << " Execution grade : " << obj.getExecuteGrade() << " Status : " << ((obj.getStatus())? "SIGNED" : "NOT SIGNED")<< std::endl;
	return out;
}
