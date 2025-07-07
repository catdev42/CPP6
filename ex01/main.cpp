#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data *dataPtr = new Data();
	std::cout << dataPtr << std::endl;

	uintptr_t intPtr = Serializer::serialize(dataPtr);
	std::cout << "0x" << std::hex << intPtr << std::dec << std::endl;
	Data *newPtr = Serializer::deserialize(intPtr);
	std::cout << newPtr << std::endl;
}
