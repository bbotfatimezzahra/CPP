#include "RPN.hpp"
#include <iostream>

RPN::RPN(){};

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN(){};

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return *this;
}

bool isOperator(char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}

bool  RPN::checkExpression(char *exp)
{
	while (*exp)
	{
		if (!std::isdigit(*exp) && !isOperator(*exp) && *exp != ' ')
			return false;
		exp++;
	}
	return true;
}

int 	operate(int a, int b, char op)
{
	if (op == '+')
		a += b;
	if (op == '-')
		a -= b;
	if (op == '*')
		a *= b;
	if (op == '/')
		a /= b;
	return (a);
}

bool 	RPN::calculateOperation(char *exp)
{
	int c;

	while (*exp)
	{
		if (std::isdigit(*exp))
			_stack.push((*exp) - '0');
		if (isOperator(*exp))
		{
			if (_stack.size() < 2)
				return false;
			c = _stack.top(); _stack.pop();
			c = operate(_stack.top(), c, *exp);
			_stack.pop(); _stack.push(c);
		}
		exp++;
	}
	if (_stack.size() > 1)
		return false;
	std::cout << _stack.top() << std::endl;
	return true;
}

RPN::RPN(char *exp)
{
	if (!checkExpression(exp))
	{
		std::cerr <<"Error"<<std::endl;
		return;
	}
	if (!calculateOperation(exp))
	{
		std::cerr <<"Error"<<std::endl;
		return;
	}
}

