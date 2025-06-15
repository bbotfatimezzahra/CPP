#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &rhs);
		AForm	*makeForm(std::string name, std::string target) const;
};

#endif
