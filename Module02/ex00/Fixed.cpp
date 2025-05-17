#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionbits = 8;

Fixed::Fixed() : _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &og) : _rawbits(og._rawbits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &og)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->setRawBits(og.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}
