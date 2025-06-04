#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	Ice *a = new Ice();
	Cure *b = new Cure();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(a);
	src->learnMateria(b);
	src->learnMateria(b);
	ICharacter* me = new Character("fati");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure1");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->use(0, *bob);
	tmp =  src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete a;
	delete b;

	return 0;
}
