#include <iostream>
#include <cstdint>
#include "Data.hpp"

std::uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data *deserialize(std::uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data data;
	data.member = 42;

	std::cout \
	<< "\naddress : " << &data \
	<< "\nvalue : " << data.member << std::endl;

	std::uintptr_t tempptr = serialize(&data);
	Data *newptr = deserialize(tempptr);

	std::cout \
	<< "\naddress : " << newptr \
	<< "\nvalue : " << newptr->member << std::endl;
}