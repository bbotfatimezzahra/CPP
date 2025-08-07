#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include<exception>
# include<algorithm>

class NotFoundException : public std::exception
{
	public :
		const char *what() const throw(){
			return "Element not found";
		}
};

template<typename T>
typename T::iterator easyfind(T &con, int num)
{
	typename T::iterator	it = std::find(con.begin(), con.end(), num);
	if (it == con.end())
		throw NotFoundException();
	else
		return it;
}

#endif
