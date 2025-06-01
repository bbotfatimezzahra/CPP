/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:58:49 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 18:58:59 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int	N = 5;
	Zombie*	horde = zombieHorde(N, "Zooooooo");
	while (--N >= 0)
		horde[N].announce();
	delete [] horde;
	return (0);
}
