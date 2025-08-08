#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include<algorithm>
# include<stack>

template<typename T>
class MutantStack
{
	private :
		std::stack<T>	_stack;
	public :
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &rhs);
		~MutantStack();
		T &top();
		bool empty() const;
		int size()const;
		void push(const T &elem);
		void pop();
		begin();
		rbegin();
		end();
		rend();
};

#endif
