#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &rhs);
		std::string const & getType() const;
		void	setType(const std::string &type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

typedef struct s_Materia
{
	AMateria *m;
	s_Materia *next;
}	t_Materia;

t_Materia *newNode(AMateria *m);
void	addNode(t_Materia **lst, t_Materia *node);
void	deleteList(t_Materia **lst);

#endif
