# include <iostream>
# include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Input file needed" << std::endl;
		return 0;
	}
	try
	{
		BitcoinExchange run(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
