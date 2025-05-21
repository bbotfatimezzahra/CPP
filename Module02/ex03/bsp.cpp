#include "Point.hpp"
#include <iostream>

static Fixed	abs(Fixed f)
{
	if (f < 0)
		f = f * -1;
	return f;
}

float	area(Point const &a, Point const &b, Point const &c)
{
	Fixed	temp;

	temp = a.getX() * (b.getY() - c.getY());
	temp += b.getX() * (c.getY() - a.getY());
	temp += c.getX() * (a.getY() - b.getY());
	
	return ((abs(temp).toFloat()) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	m = area(a, b, c);
	float	m1 = area(point, b, a);
	float	m2 = area(point, a, c);
	float	m3 = area(point, b, c);

	if (m1 > 0 && m2 > 0 && m3 > 0)
		return (m == (m1 + m2 + m3));
	else
		return (false);
}
