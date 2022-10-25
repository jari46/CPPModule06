#include <iostream>
#include <cstdint>
#include "Data.hpp"

//typedef unsigned long uintptr_t

std::uintptr_t serialize(Data *ptr);
Data *deserialize(std::uintptr_t raw);

int main() {
	Data data;
	data.member = 42;

	std::cout \
	<< "\naddress : " << &data \
	<< "\nvalue : " << data.member << std::endl;

	std::uintptr_t tempptr = serialize(&data);//It can typecast any pointer to any other data type.
	Data *newptr = deserialize(tempptr);//pointer data type should be same as original data type.

	std::cout \
	<< "\naddress : " << newptr \
	<< "\nvalue : " << newptr->member << std::endl;
}

std::uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data *deserialize(std::uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}