#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "** Trying the subject's tests **" << std::endl;
		
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
		std::cout << "\n** Adding some random numbers to the span **" << std::endl;

		Span	sp1(5);
		int		n;

		srand(time(NULL));
		for (int i = 0; i < 5; i++)
		{
			n = rand() % 100;
			std::cout << "Adding the number " << n << " to the span" << std::endl;
			sp1.addNumber(n);
		}

		std::cout << "\n" << sp1 << std::endl;

		std::cout << "\n** Adding more than the span can handle **" << std::endl;
		sp1.addNumber(4);

		std::cout << "\n** Adding elements with iterators **" << std::endl;
		std::vector<int>	vect;
		Span				sp2(10);

		for (int i = 0; i < 10; i++)
			vect.push_back(rand() % 100);

		sp2.addRange(vect.begin(), vect.end());
		std::cout << sp2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " <<e.what() << std::endl;
	}
	return (0);
}
