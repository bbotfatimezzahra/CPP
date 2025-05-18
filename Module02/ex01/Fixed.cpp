#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionbits = 8;

Fixed::Fixed() : _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &og) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = og;
}

Fixed::Fixed(int const &value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawbits = (value * (1 << Fixed::_fractionbits));
}

Fixed::Fixed(float const &value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawbits = roundf(value * (1 << Fixed::_fractionbits));
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
	return (this->_rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}

float	Fixed::toFloat(void) const
{
	float	result;

	result = float(_rawbits) / (1 << Fixed::_fractionbits);
	return result;
}

int	Fixed::toInt(void) const
{
	int	result;

	result = _rawbits / (1 << Fixed::_fractionbits);
	return result;
}

std::ostream & operator<<(std::ostream & out, Fixed const & og)
{
	out << og.toFloat();
	return out;
}
