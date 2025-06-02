#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	std::string	ideas[100];

	public :
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &rhs);
};

#endif
