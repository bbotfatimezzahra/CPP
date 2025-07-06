#include "Base.hpp"
#include <iostream>

int main(void)
{
	//Base	*obj = generate();
	Base	*obj = new Base();
	identify(obj);
	identify(*obj);
	delete obj;
	return 0;
}
