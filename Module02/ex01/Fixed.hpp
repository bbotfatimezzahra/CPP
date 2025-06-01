/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:16:55 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 20:17:40 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Fixed(Fixed const &other);
		Fixed(const int &val);
		Fixed(const float &val);
		~Fixed();
		Fixed & operator=(Fixed const &other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &og);
#endif
