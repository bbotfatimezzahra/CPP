#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

const std::string	&AMateria::getType(void) const
{
	return _type;
}

void	AMateria::setType(const std::string &type)
{
	_type = type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

//=============================MATERIA LINKED LIST FUNCS====================

t_Materia *newNode(AMateria *m)
{
	t_Materia	*node = new t_Materia;
	
	node->m = m;
	node->next = NULL;
	return node;
}

void	addNode(t_Materia **lst, t_Materia *node)
{
	t_Materia	*last;

	if (!lst || !node)
		return ;
	if (!*lst)
		*lst = node;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}

void	deleteList(t_Materia **lst)
{
	t_Materia *tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		delete tmp->m;
		delete tmp;
	}
	*lst = NULL;
}
