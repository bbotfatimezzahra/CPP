#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( 1.2f );
	Fixed const c( 4.4f );
	int res = b.getRawBits() + c.getRawBits();
	/*Fixed const d( b + c);

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	*/std::cout << "b is " << b.getRawBits() << " to float" << b <<std::endl;
	std::cout << "c is " << c.getRawBits() << " to float" << c <<std::endl;
	std::cout << "res is " << res <<std::endl;

	return 0;
}
