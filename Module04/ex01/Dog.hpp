#pragma once
#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private :
		Brain	*_brain;
	public :
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &rhs);
		Brain	*getBrain(void) const;
		void	setBrain(const Brain &brain);
		void	makeSound(void) const;
};

#endif
