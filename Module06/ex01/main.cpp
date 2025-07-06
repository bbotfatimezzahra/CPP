#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data = {1};
	uintptr_t raw = Serializer::serialize(&data);
	Data *res = Serializer::deserialize(raw);
	std::cout << "number: " << res->num << std::endl;
}
