#include <exception>

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	_size = copy.size();
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy[i];
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size)
		throw OutOfBoundException();
	else 
		return _arr[idx];
}

template <typename T>
Array<T> Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] _arr;
		_size = rhs.size();
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = rhs[i];
	}
	return *this;
}

