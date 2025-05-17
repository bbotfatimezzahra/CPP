#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private :
		int	_rawbits;
		static const int	_fractionbits;
	public :
		Fixed();
		Fixed(Fixed const &og);
		~Fixed();
		Fixed & operator=(Fixed const &og);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
