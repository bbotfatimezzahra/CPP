#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria*	_sources[4];
		int	_slots;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &rhs);
		int	getSlots()const;
		AMateria *getMateria(int idx) const;
		AMateria *getMateria(const std::string &type) const;
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
