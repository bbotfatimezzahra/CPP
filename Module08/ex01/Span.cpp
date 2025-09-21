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
	if (this != &rhs)
	{

		_size = rhs.getSize();
		_con = rhs.getCon();
	}
	return *this;
}

Span::~Span()
{
}

unsigned int	Span::getSize() const
{
	return _size;
}

std::vector<int>	Span::getCon() const
{
	return _con;
}

void Span::addNumber(int elem)
{
	if (_con.size() < _size)
		_con.push_back(elem);
	else
		throw FullCapacityException();
}

void Span::addRange(std::vector<int>::iterator begin,std::vector<int>::iterator end)
{
	for (;begin != end ; ++begin)
		this->addNumber(*begin);
}

int Span::shortestSpan() const
{
	if (_size <= 1)
		throw NoSpanException();
	std::vector<int>	temp = _con;
	std::sort(temp.begin(), temp.end());
	int	res = temp.back();
	for (std::size_t i = 0; i < temp.size() - 1; ++i)
	{
		if (res > (temp[i + 1] - temp[i]))
			res = temp[i + 1] - temp[i];
	};
	return res;
}

int Span::longestSpan() const
{
	if (_size <= 1)
		throw NoSpanException();
	std::vector<int>	temp = _con;
	std::sort(temp.begin(), temp.end());
	return (temp.back() - temp.front());
}

std::ostream &operator<<(std::ostream &out, const Span &c)
{
	std::vector<int> temp = c.getCon();
	for (std::vector<int>::const_iterator it = temp.begin(); it != temp.end() ; ++it)
		out << *it << " " ;
	std::cout << std::endl;
	return out;
}
