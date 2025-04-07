#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private :
		std::String	first_name;
		std::String	last_name;
		std::String	nickname;
		std::String	phone_number;
		std::String	darkest_secret;

	public :
		Contact(void);
		Contact(std::String first,std::String last,std::String nick,std::String phone,std::String secret); 
		~Contact(void);
		void	display(void);
};

#endif
