#pragma once
#ifndef RPN_HPP
# define RPN_HPP
# include <stack>

class RPN
{
	private :
		std::stack<int> _stack;
		RPN();
	public :
		RPN(const RPN &copy);
		~RPN();
		RPN &operator=(const RPN &rhs);
		RPN(char *exp);
		bool  checkExpression(char *exp);
		bool 	calculateOperation(char *exp);
};

#endif
