/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:03:52 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:04:05 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class	Weapon
{
	private :
		std::string	_type;
	public :
		Weapon(std::string type);
		~Weapon();
		const std::string& getType(void) const;
		void	setType(std::string type);
};

#endif
