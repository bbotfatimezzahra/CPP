#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	*this = copy;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--; 
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!!";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}
