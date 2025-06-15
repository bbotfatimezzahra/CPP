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

class APresidentialPardonFormForm
{
	private :
		const std::string	_name;
		bool	_status;
		const	int	_signGrade;
		const	int	_executeGrade;
		PresidentialPardonFormForm();
	public :
		PresidentialPardonFormForm(const PresidentialPardonFormForm &copy);
		PresidentialPardonFormForm(std::string name, int signGrade, int executeGrade);
		virtual ~PresidentialPardonFormForm();
		PresidentialPardonFormForm &operator=(const PresidentialPardonFormForm &rhs);
		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		bool	getStatus(void) const;
		void	beSigned(const Bureaucrat &signer);
		virtual execute(const Bureaucrat &executor);
		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonFormForm &obj);

#endif
