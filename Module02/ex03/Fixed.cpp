/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:21:26 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 20:22:06 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionBits = 8;

//=======================DE/CONSTRUCTORS=======================//

Fixed::Fixed() : _fixedValue(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) 
{
//	std::cout << "Copy constructor called" << std::endl;
	_fixedValue = copy.getRawBits();
}

Fixed::Fixed(const int &value)
{
//	std::cout << "Int constructor called" << std::endl;
	_fixedValue = value << _fractionBits;
}

Fixed::Fixed(const float &value)
{
//	std::cout << "Float constructor called" << std::endl;
	_fixedValue = roundf(value * (1 << _fractionBits));
}

Fixed::~Fixed()
{
//	std::cout << "Deconstructor called" << std::endl;
}

//==================MEMBER FUNCTIONS==========================//

Fixed &Fixed::operator=(const Fixed &other)
{
//	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedValue);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixedValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float(_fixedValue) / (1 << _fractionBits));
}

int	Fixed::toInt(void) const
{
	return (_fixedValue >> _fractionBits);
}

//==================COMPARISON OPERATORS==========================//

bool Fixed::operator>(const Fixed &other) const
{
	return (_fixedValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixedValue < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (!(*this < other));
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (!(*this > other));
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_fixedValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (!(*this == other));
}

//==================DE/INCREMENT OPERATORS=========================//

Fixed & Fixed::operator++()
{
	_fixedValue++;
	return *this;
}

Fixed & Fixed::operator--()
{
	_fixedValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	old(*this);
	operator++();
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed	old(*this);
	operator--();
	return old;
}

//==================ARITHMETIC OPERATORS=========================//

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed &Fixed::operator+=(const Fixed &rhs)
{
	*this = *this + rhs;
	return (*this);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

//==================MIN/MAX FUNCTIONS OVERLOAD=====================//

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b ? a : b));
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b ? a : b));
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b ? a : b));
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b ? a : b));
}

//==================<< OPERATOR OVERLOAD=====================//

std::ostream & operator<<(std::ostream & out, const Fixed & og)
{
	out << og.toFloat();
	return out;
}

