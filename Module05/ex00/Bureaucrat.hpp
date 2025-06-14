#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include <string>
# include <ostream>
# include <exception>

class Bureaucrat
{
	private :
		const std::string	_name;
		int	_grade;
		Bureaucrat();
	public :
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);
		const std::string &getName(void) const;
		int getGrade(void) const;
		void	setGrade(int grade);
		void	incrementGrade();
		void	decrementGrade();
		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
