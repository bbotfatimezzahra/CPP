#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include <ostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string	_name;
		bool	_status;
		const	int	_signGrade;
		const	int	_executeGrade;
	public :
		AForm();
		AForm(const AForm &copy);
		AForm(std::string name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);
		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		bool	getStatus(void) const;
		void	beSigned(const Bureaucrat &signer);
		virtual void execute(const Bureaucrat &executor) const = 0;
		class GradeTooHighException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif
