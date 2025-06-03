#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		~AMateria();
		AMateria &operator=(const AMateria &rhs);
		std::string const & getType() const;
		void	setType(const std::string &type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
