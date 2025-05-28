#pragma once
#ifndef DIAMOND_HPP
# define DIAMOND_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	private :
		std::string	_name;
	public :
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		std::string	getName(void) const;
		void	attack(const std::string &target);
		void	whoAmI(void);
};

#endif
