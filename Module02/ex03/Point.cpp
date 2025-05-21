#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
//	std::cout << "Default Constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
//	std::cout << "Parameterised Constructor called" << std::endl;
}

Point::Point(const Point &copy)
{
	*this = copy;
//	std::cout << "Copy Constructor called" << std::endl;
}

Point::~Point()
{
//	std::cout << "Deconstructor called" << std::endl;
}

Point & Point::operator=(const Point &rhs)
{
	(Fixed)_x = rhs.getX();
	(Fixed)_y = rhs.getY();
//	std::cout << "Assignement operator called" << std::endl;
	return *this;
}

Fixed	Point::getX(void) const { return (_x); }

Fixed	Point::getY(void) const { return (_y); }
