#pragma once
#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &rhs);
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif
