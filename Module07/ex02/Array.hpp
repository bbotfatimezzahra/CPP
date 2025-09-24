#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstddef>
# include <iostream>
# include <ostream>

template<typename T>
class Array
{
	private :
		T *_arr;
		unsigned int	_size;
	public :
		Array(): _arr(NULL), _size(0){};
		Array(unsigned int n): _arr(new T[n]), _size(n){};
		Array(const Array<T> &copy);
		Array<T> operator=(const Array<T> &rhs);
		T& operator[](unsigned int idx) const;
		~Array(){delete[] _arr;};
		unsigned int size()const {return _size;};
		class OutOfBoundException : public std::exception {
			public :
				const char *what() const throw(){
					return "Out Of Bound Index";};
		};
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &c)
{
	for (size_t i=0; i<c.size();i++)
		out << c[i] << std::endl;
	return out;
}
# include "Array.tpp"
#endif
