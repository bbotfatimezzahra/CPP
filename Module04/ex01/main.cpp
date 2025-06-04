#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//const Animal* j = new Dog();
	//const Animal* i = new Cat();

	 Cat tmp ;
	 tmp.getBrain()->setIdea(0,"waaaa");
	 Cat basic(tmp);
	 basic.getBrain()->setIdea(0,"booo");
	 basic = tmp;
	 std::cout << "tmp = " << tmp.getBrain()->getIdea(0) << "basic = " << basic.getBrain()->getIdea(0);
//	delete i;//should not create a leak
//	delete j;
	return 0;
}
