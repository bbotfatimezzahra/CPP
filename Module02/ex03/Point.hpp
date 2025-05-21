#pragma once
#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &copy);
		Point & operator=(const Point &rhs);
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
