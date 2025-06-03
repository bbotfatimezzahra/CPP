#pragma once
#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
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
