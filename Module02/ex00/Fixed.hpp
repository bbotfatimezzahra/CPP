/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:15:25 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 20:15:35 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Fixed(Fixed const &other);
		~Fixed();
		Fixed & operator=(Fixed const &other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
