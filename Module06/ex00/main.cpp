#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage : ./Scalar <argument>"<< std::endl;
		return 0;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}
