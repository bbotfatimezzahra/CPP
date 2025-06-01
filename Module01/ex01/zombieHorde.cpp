/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:58:56 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 18:58:59 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	while (--N >= 0)
		horde[N].set_name(name);
	return(horde);
}
