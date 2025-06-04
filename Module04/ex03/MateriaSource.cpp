#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	_slots = 0;
	for (int i=0; i < 4; i++)
		_sources[i] = NULL;
	std::cout << "MateriaSource is created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	_slots = copy.getSlots();
	for (int i=0; i < 4; i++)
	{
		if (copy.getMateria(i))
			_sources[i] = copy.getMateria(i)->clone();
		else
			_sources[i] = NULL;
	}
	std::cout << "MateriaSource is created" << std::endl;

}

MateriaSource::~MateriaSource()
{
	int i=0;
	while (_slots)
	{
		if (_sources[i])
		{
			delete _sources[i++];
			_slots--;
		}
	}
	std::cout << "MateriaSource is destructed" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		_slots = rhs.getSlots();
		for (int i=0; i<4; i++)
		{
			if (getMateria(i))
				delete _sources[i];
			if (rhs.getMateria(i))
				_sources[i] = rhs.getMateria(i)->clone();
			else
				_sources[i] = NULL;
		}
	}
	return *this;
}

int	MateriaSource::getSlots()const
{
	return _slots;
}

AMateria *MateriaSource::getMateria(int idx) const
{
	if (idx >=0 && idx < 4)
		return _sources[idx];
	return NULL;
}

AMateria *MateriaSource::getMateria(const std::string &type) const
{
	int i = 0;

	while (_sources[i] && _sources[i]->getType().compare(type))
		i++;
	if (i == 4)
		return (NULL);
	else
		return _sources[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		std::cout << "Null Materia" << std::endl;
	else if (_slots < 4)
	{
		int i = 0;
		while (_sources[i])
			i++;
		_sources[i] = m->clone();
		_slots++;
		std::cout << m->getType() << " added to the MateriaSource" << std::endl;
	}
	else
		std::cout << "MateriaSource is Full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i=0; i < 4; i++)
	{
		if (_sources[i] && !(_sources[i]->getType()).compare(type))
			return (_sources[i]->clone());
	}
	return NULL;
}
