#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int n)
{
	_size = n;
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != rhs)
	{

		_size = rhs.getSize();
		_con = rhs.getCon();
	}
	return this;
}

Span::~Span()
{
}

unsigned int	Span::getSize() const
{
	return _size;
}

std::vector	Span::getCon() const
{
	return _con;
}

void Span::addNumber(int elem)
{
}

int Span::shortestSpan() const
{
}

int Span::longestSpan() const
{
}

std::ostream &operator<<(std::ostream &out, const Span &c)
{
	return out;
}
