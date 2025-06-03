#pragma once
#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private :
		Brain	*_brain;
	public :
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &rhs);
		Brain	*getBrain(void) const;
		void	setBrain(const Brain &brain);
		void	makeSound(void) const;
};

#endif
