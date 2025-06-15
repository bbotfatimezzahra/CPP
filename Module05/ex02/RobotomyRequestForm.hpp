#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <ostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
		RobotomyRequestForm();
	public :
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		std::string	getTarget(void) const;
		void execute(const Bureaucrat &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &obj);

#endif
