#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <ostream>

class Fixed
{
	private :
		int	_rawbits;
		static const int	_fractionbits;
	public :
		Fixed();
		Fixed(Fixed const &og);
		Fixed(const int &val);
		Fixed(const float &val);
		~Fixed();
		Fixed & operator=(Fixed const &og);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &og);
#endif
