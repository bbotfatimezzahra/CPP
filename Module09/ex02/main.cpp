#include"PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error"<< std::endl;
		return 0;
	}
	if (!checkArgs(argv))
	{
		std::cerr << "Error"<< std::endl;
		return 0;
	}
	try
	{
		PmergeMe merge(argc,argv);
		merge.execute();
//		print_cont(merge);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
