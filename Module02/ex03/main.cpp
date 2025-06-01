/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:21:59 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 20:22:06 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void )
{
	if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(0, 0)))
		std::cout <<"Inside";
	else
		std::cout <<"Not Inside";

	return 0;
}
