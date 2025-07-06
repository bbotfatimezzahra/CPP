#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base::~Base()
{}

Base * generate(void)
{
	std::srand(std::time(NULL));
	int i = std::rand() % 3;
	if (!i)
	{
		std::cout << "Created class A"<< std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Created class B"<< std::endl;
		return new B;
	}
	else
	{
		std::cout << "Created class C"<< std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to class C" << std::endl;
	else
		std::cout << "Bad Cast" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to class A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Reference to class B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Reference to class C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Bad Cast" << std::endl;
			}

		}
	}
}
