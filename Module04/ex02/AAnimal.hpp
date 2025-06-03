#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>

class	AAnimal
{
	protected :
		std::string	_type;
	public :
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &rhs);
		std::string	getType(void) const;
		void	setType(const std::string &type);
		virtual void	makeSound(void) const = 0;
};

#endif
