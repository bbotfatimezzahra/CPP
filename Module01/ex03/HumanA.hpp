/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:03:16 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 19:04:05 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class	HumanA
{
	private	:
		std::string	_name;
		Weapon&	_weapon;
	public :
		HumanA(std::string name,Weapon& weapon);
		~HumanA();
		void	attack(void);
};

#endif
