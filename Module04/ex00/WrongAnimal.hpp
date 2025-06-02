#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class	WrongAnimal
{
	protected :
		std::string	_type;
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &rhs);
		std::string	getType(void) const;
		void	setType(std::string type);
		void	makeSound(void) const;
};

#endif
