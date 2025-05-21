#include "Point.hpp"
#include <iostream>

int main( void )
{
	if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(0, 0)))
		std::cout <<"Inside";
	else
		std::cout <<"Not Inside";

	return 0;
}
