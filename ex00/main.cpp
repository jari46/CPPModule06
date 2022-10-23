#include <iostream>
#include "Convert.hpp"

//takes as parameter a string representation of a scalar types
//: char, int, float or double. 
//Except for char parameters, only the decimal notation will be used

int main(int argc, char **argv) {
	if (argc == 2) {
		std::cout << Convert(argv[1]) << std::endl;
	} else {
		std::cout << "Usage: ./convert [number to convert]" << std::endl;
	}
}
