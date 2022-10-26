#include <iostream>
#include <cstdint>
#include "Data.hpp"

//typedef unsigned long uintptr_t

std::uintptr_t serialize(Data *ptr);
Data *deserialize(std::uintptr_t number);

int main() {
	Data data;
	data.member = 42;

	std::cout << "* data *" \
	<< "\naddress : " << &data \
	<< "\nvalue : " << data.member << std::endl;

	std::uintptr_t number = serialize(&data);//It can typecast any pointer to any other data type.
	Data *newDataPtr = deserialize(number);//pointer data type should be same as original data type.

	std::cout << "\n* new data *" \
	<< "\naddress : " << newDataPtr \
	<< "\nvalue : " << newDataPtr->member << std::endl;
}

std::uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data *deserialize(std::uintptr_t number) {
	return reinterpret_cast<Data *>(number);
}