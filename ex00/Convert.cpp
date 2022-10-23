#include <iostream>
#include <cstdlib>//stdtod()
#include <iomanip>//
#include "Convert.hpp"

int	Convert::getCastingToInt() const {
	return static_cast<int>(mInput);
}

float	Convert::getCastingToFloat() const {
	return static_cast<float>(mInput);
}

double	Convert::getCastingToDouble() const {
	return static_cast<double>(mInput);
}

void Convert::displayToInt() const {
	std::cout << std::setprecision(1) << getCastingToInt() << std::endl;
}

void Convert::displayToFloat() const {
	std::cout << std::fixed << std::setprecision(1) << getCastingToFloat() << "f" << std::endl;
}

void Convert::displayToDouble() const {
	std::cout << std::fixed << std::setprecision(1) << getCastingToDouble() << std::endl;
}

//--------------------------------------------------------//

Convert::Convert() {}

/* What we gonna use!! */
Convert::Convert(std::string input) {
	mInput = std::strtod(input.c_str(), &mEndptr);
}

Convert::Convert(const Convert& src) {
	(*this) = src;
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src) {
	}
	return *this;
}

Convert::~Convert() {}

//--------------------------------------------------------//

double Convert::getInput() const {
	return mInput;
}
char *Convert::getEndptr() const {
	return mEndptr;
}

//--------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, Convert const &convert) {
	std::cout << "char: " << (convert.getEndptr())[0] << std::endl;
	std::cout << "int: "; convert.displayToInt();
	std::cout << "float: "; convert.displayToFloat();
	std::cout << "double: "; convert.displayToDouble();
	return os;
}
