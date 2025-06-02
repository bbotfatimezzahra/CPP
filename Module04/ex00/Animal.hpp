#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class	Animal
{
	protected :
		std::string	_type;
	public :
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);
		std::string	getType(void) const;
		void	setType(std::string type);
		virtual void	makeSound(void) const;
};

#endif
