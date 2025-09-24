#include "ScalarConverter.hpp"
#include <iostream>
#include<limits.h>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage : ./Scalar <argument>"<< std::endl;
		return 0;
	}

	ScalarConverter::convert(av[1]);
	std::cout<<__DBL_MAX__<<std::endl;
	return 0;
}
