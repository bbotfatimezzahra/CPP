#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string	_name;
		AMateria	*_inventory[4];
		int	_slots;
		t_Materia	*_left;
	public :
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &rhs);
		const std::string &getName(void) const;
		int getSlots(void) const;
		const AMateria *getMateria(int i) const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif
