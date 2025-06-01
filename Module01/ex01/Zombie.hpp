/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:58:44 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 18:58:59 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class	Zombie 
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);
		void set_name(std::string name);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
