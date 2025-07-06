#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <cstdint>

struct Data
{
	int	num;
};

class Serializer
{
	private :
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
