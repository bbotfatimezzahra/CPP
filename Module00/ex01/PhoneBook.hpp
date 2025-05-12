#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	PhoneBook
{
	private :
		Contact	_conts[8];
		int	_index;
	public :
		PhoneBook();
		~PhoneBook();
		void	add(void);
		void	display(void) const;
		void	find(void) const;
};

#endif
