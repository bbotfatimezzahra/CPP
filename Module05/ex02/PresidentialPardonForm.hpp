#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <ostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
		PresidentialPardonForm();
	public :
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		std::string	getTarget(void) const;
		void execute(const Bureaucrat &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &obj);

#endif
