#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	private :
		std::string	_ideas[100];
	public :
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &rhs);
		std::string	getIdea(int i)const;
		void	setIdea(int i, const std::string &idea);
};

#endif
