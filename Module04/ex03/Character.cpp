#include "Character.hpp"
#include <iostream>
#include <cstdlib>

Character::Character(): _name("Rando"), _slots(0) , _left(NULL)
{
	for (int i=0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " entered the game"<< std::endl;
}

Character::Character(const std::string &name): _name(name), _slots(0), _left(NULL)
{
	for (int i=0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " entered the game"<< std::endl;
}

Character::Character(const Character &copy)
{
	_name = copy.getName();
	_slots = copy.getSlots();
	_left = NULL;
	for (int i=0; i < 4; i++)
	{
		if (copy.getMateria(i))
			_inventory[i] = copy.getMateria(i)->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " entered the game"<< std::endl;
}

Character::~Character()
{
	std::cout << "Character " << _name << " exited the game"<< std::endl;
	int i=0;
	while (_slots)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_slots--;
		}
		i++;
	}
	deleteList(&_left);
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character " << _name << " changed to "<< rhs.getName() << std::endl;
	if (this != &rhs)
	{
		_name = rhs.getName();
		_slots = rhs.getSlots();
		for (int i=0; i<4; i++)
		{
			if (getMateria(i))
				delete _inventory[i];
			if (rhs.getMateria(i))
				_inventory[i] = rhs.getMateria(i)->clone();
			else
				_inventory[i] = NULL;
		}
		deleteList(&_left);
		_left = NULL;
	}
	return *this;
}

const std::string &Character::getName(void) const
{
	return _name;
}

int Character::getSlots(void) const
{
	return _slots;
}

const AMateria *Character::getMateria(int idx) const
{
	if (idx >=0 && idx < 4)
		return _inventory[idx];
	return NULL;
}

void	Character::equip(AMateria *m)
{
	if (!m)
		std::cout << "Null Materia" << std::endl;
	else if (_slots < 4)
	{
		int i = 0;
		while (_inventory[i])
			i++;
		_inventory[i] = m;
		_slots++;
		std::cout << _name << " equiped with "<< m->getType() << std::endl;
	}
	else
		std::cout << _name << " has Full Inventory" << std::endl;
	}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		addNode(&_left, newNode(_inventory[idx]));
		std::cout << _name << " unequiped of "<< _inventory[idx]->getType() << std::endl;
		_inventory[idx] = NULL;
		_slots--;
	}
	else
		std::cout << _name << " has No Materia in slot " <<idx << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >=0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);	
	else
		std::cout << _name << " has No Materia in slot " <<idx << std::endl;
}

