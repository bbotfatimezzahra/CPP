#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//const AAnimal* j = new Dog();
	//const AAnimal* i = new Cat();

//	const AAnimal* anim = new AAnimal();
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
