#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy)
{
	*this = copy;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	this.c.operator=(rhs);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(){};

template<typename T>
iterator MutantStack<T>::begin()
{
	return c.begin();
}

template<typename T>
iterator MutantStack<T>::rbegin()
{
	return c.rbegin();
}

template<typename T>
iterator MutantStack<T>::end()
{
	return c.end();
}

template<typename T>
iterator MutantStack<T>::rend()
{
	return c.rend();
}

