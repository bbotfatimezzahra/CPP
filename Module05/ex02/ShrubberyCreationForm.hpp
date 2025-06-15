#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <ostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;
		ShrubberyCreationForm();
	public :
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		std::string	getTarget(void) const;
		void execute(const Bureaucrat &executor) const;
		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw();
		};
		class NotSignedException : public std::exception{
			public :
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &obj);

#endif
