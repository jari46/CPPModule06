#include <iostream>
#include <cstdlib>//stdtod()
#include <iomanip>//setprecision()
#include <cmath>//isnan
#include <cctype>//isprint
#include "Convert.hpp"

void Convert::displayToChar() const {
	if (mActualChar != NULL)
		std::cout << *mActualChar;
	if (mActualInt != NULL) {
		if (isprint(*mActualInt))
			std::cout << static_cast<char>(*mActualInt);
		else
			std::cout << "Non displayable";
	}
	if (mActualFloat != NULL) {
			if (isprint(*mActualFloat))
			std::cout << static_cast<char>(*mActualFloat);
		else
			std::cout << "Non displayable";
	}
	if (mActualDouble != NULL) {
			if (isprint(*mActualDouble))
			std::cout << static_cast<char>(*mActualDouble);
		else
			std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

void Convert::displayToInt() const {
	if (mActualChar != NULL)
		std::cout << static_cast<int>(*mActualChar);
	if (mActualInt != NULL)
		std::cout << *mActualInt;
	if (mActualFloat != NULL) {
		if (isnan(*mActualFloat) == true || isinf(*mActualFloat) == true)
			std::cout << "Impossible";
		else
			std::cout << static_cast<int>(*mActualFloat);
	}
	if (mActualDouble != NULL) {
		if (isnan(*mActualDouble) == true || isinf(*mActualDouble) == true)
			std::cout << "Impossible";
		else
			std::cout << static_cast<int>(*mActualDouble);
	}
	std::cout << std::endl;
}

void Convert::displayToFloat() const {
	std::cout << std::fixed << std::setprecision(1);
	if (mActualChar != NULL)
		std::cout << static_cast<float>(*mActualChar);
	if (mActualInt != NULL)
		std::cout << static_cast<float>(*mActualInt);
	if (mActualFloat != NULL)
		std::cout << static_cast<float>(*mActualFloat);
	if (mActualDouble != NULL)
		std::cout << static_cast<float>(*mActualDouble);
	std::cout << "f" << std::endl;
}

void Convert::displayToDouble() const {
	std::cout << std::fixed << std::setprecision(1);
	if (mActualChar != NULL)
		std::cout << static_cast<double>(*mActualChar);
	if (mActualInt != NULL)
		std::cout << static_cast<double>(*mActualInt);
	if (mActualFloat != NULL)
		std::cout << static_cast<double>(*mActualFloat);
	if (mActualDouble != NULL)
		std::cout << static_cast<double>(*mActualDouble);
}

//--------------------------------------------------------//

Convert::Convert() {}

/* What we gonna use!! */
Convert::Convert(char *input)
	: mRawString(input), mActualChar(NULL), mActualInt(NULL), mActualFloat(NULL), mActualDouble(NULL) {
	
	// 0. number type
	char *endptr;
	double temp = std::strtod(mRawString, &endptr);

	if (mRawString != endptr || isnan(temp) == true || isinf(temp) == true) {
		// 1. float, double type
		if (std::string(mRawString).find('.') == true || isnan(temp) == true || isinf(temp) == true)
			if (*endptr == 'f')
				mActualFloat = new float(static_cast<float>(std::strtod(mRawString, NULL)));
			else
				mActualDouble = new double(static_cast<double>(std::strtod(mRawString, NULL)));
		// 2. int type
		else
			mActualInt = new int(static_cast<int>(std::strtod(mRawString, NULL)));
	}
	// 3. char type
	else
		mActualChar = new char(mRawString[0]);
}

Convert::Convert(const Convert& src) {
	(*this) = src;
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src) {
	}
	return *this;
}

Convert::~Convert() {
	delete mActualChar;
	delete mActualInt;
	delete mActualFloat;
	delete mActualDouble;
}

//--------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, Convert const &convert) {
	std::cout << "char: "; convert.displayToChar();
	std::cout << "int: "; convert.displayToInt();
	std::cout << "float: "; convert.displayToFloat();
	std::cout << "double: "; convert.displayToDouble();
	return os;
}
