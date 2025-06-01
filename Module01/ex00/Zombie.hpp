/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:55:56 by fbbot             #+#    #+#             */
/*   Updated: 2025/06/01 18:56:26 by fbbot            ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
