#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data = {1};
	uintptr_t raw = Serializer::serialize(&data);
	Data *res = Serializer::deserialize(raw);

	std::cout << "data number: " << data.num << std::endl;
	std::cout << "raw address: " << raw << std::endl;
	std::cout << "res address: " << res << std::endl;
	std::cout << "res number: " << res->num << std::endl;
}
