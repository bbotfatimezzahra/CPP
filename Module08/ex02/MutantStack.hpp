#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include<iostream>
# include<algorithm>
# include<stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(){};
		MutantStack(const MutantStack<T> &copy) { *this = copy; };
		MutantStack<T> &operator=(const MutantStack<T> &rhs) { this->c.operator=(rhs); return *this;};
		~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) { return this->c.begin();};
		iterator rbegin(void){ return this->c.rbegin();};
		iterator end(void){ return this->c.end();};
		iterator rend(void){ return this->c.rend();};
};

#endif
