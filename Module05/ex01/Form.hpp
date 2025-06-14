#pragma once
#ifndef FORM_HPP
# define FORM_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include <ostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		bool	_status;
		const	int	_signGrade;
		const	int	_executeGrade;
		Form();
	public :
		Form(const Form &copy);
		Form(std::string name, int signGrade, int executeGrade);
		~Form();
		Form &operator=(const Form &rhs);
		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		bool	getStatus(void) const;
		void	beSigned(const Bureaucrat &signer);
		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif
