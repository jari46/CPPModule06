#include <iostream>
#include <cstdlib>//stdtod()
#include <iomanip>//setprecision()
#include <cmath>//std::isnan()
#include <cctype>//std::isprint()
#include <limits>//numeric_limits<T>
#include "Convert.hpp"

/* What we gonna use!! */
Convert::Convert(char *input)
	: mActualChar(NULL), mActualInt(NULL), mActualFloat(NULL), mActualDouble(NULL) {
	
	// 0. number type
	char *endptr;
	double temp = std::strtod(input, &endptr);

	if (input != endptr) {
		// 1. float, double type
		if (std::string(input).find('.') != std::string::npos || std::isnan(temp) == true || std::isinf(temp) == true || \
			temp < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < temp) {
			if (*endptr == 'f')
				mActualFloat = new float(static_cast<float>(std::strtod(input, NULL)));
			else
				mActualDouble = new double(static_cast<double>(std::strtod(input, NULL)));
		}
		// 2. int type
		else
			mActualInt = new int(static_cast<int>(std::strtod(input, NULL)));
	}
	// 3. char type
	else
		mActualChar = new char(input[0]);
}

Convert::~Convert() {
	delete mActualChar;
	delete mActualInt;
	delete mActualFloat;
	delete mActualDouble;
}

//--------------------------------------------------------//

void Convert::displayToChar() const {
	// 1) from itself
	if (mActualChar != NULL)
		std::cout << "'" << *mActualChar << "'";

	// 2) from number: check whether it's printable
	else if (mActualInt != NULL) {
		if (std::isprint(*mActualInt))
			std::cout << "'" << static_cast<char>(*mActualInt) << "'";
		else
			std::cout << "Non displayable";
	}
	else if (mActualFloat != NULL) {
		if (std::isprint(*mActualFloat))
		std::cout << "'" << static_cast<char>(*mActualFloat) << "'";
		else if (std::isnan(*mActualFloat) == true || std::isinf(*mActualFloat) == true)
			std::cout << "impossible";
		else
			std::cout << "Non displayable";
	}
	else/* (mActualDouble != NULL) */ {
		if (std::isprint(*mActualDouble))
		std::cout << "'" << static_cast<char>(*mActualDouble) << "'";
		else if (std::isnan(*mActualDouble) == true || std::isinf(*mActualDouble) == true)
			std::cout << "impossible";
		else
			std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

void Convert::displayToInt() const {
	// 1) from char
	if (mActualChar != NULL)
		std::cout << static_cast<int>(*mActualChar);

	// 2) from itself
	else if (mActualInt != NULL)
		std::cout << *mActualInt;

	// 3) from float, double: check if it is nan or inf
	else if (mActualFloat != NULL) {
		if (std::isnan(*mActualFloat) == true || std::isinf(*mActualFloat) == true || \
			*mActualFloat < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < *mActualFloat)
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(*mActualFloat);
	}
	else/* (mActualDouble != NULL) */ {
		if (std::isnan(*mActualDouble) == true || std::isinf(*mActualDouble) == true || \
			*mActualDouble < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < *mActualDouble)
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(*mActualDouble);
	}
	std::cout << std::endl;
}

void Convert::displayToFloat() const {
	// 0) as fixed-pointed number(not scientific), set precision to 1
	std::cout << std::fixed << std::setprecision(1);

	if (mActualChar != NULL)
		std::cout << static_cast<float>(*mActualChar) << "f" << std::endl;
	else if (mActualInt != NULL)
		std::cout << static_cast<float>(*mActualInt) << "f" << std::endl;
	else if (mActualFloat != NULL)
		std::cout << static_cast<float>(*mActualFloat) << "f" << std::endl;
	else/* (mActualDouble != NULL) */
			std::cout << static_cast<float>(*mActualDouble) << "f" << std::endl;
}

void Convert::displayToDouble() const {
	std::cout << std::fixed << std::setprecision(1);
	if (mActualChar != NULL)
		std::cout << static_cast<double>(*mActualChar);
	else if (mActualInt != NULL)
		std::cout << static_cast<double>(*mActualInt);
	else if (mActualFloat != NULL)
		std::cout << static_cast<double>(*mActualFloat);
	else/* (mActualDouble != NULL) */
		std::cout << static_cast<double>(*mActualDouble);
	std::cout << std::endl;
}

//--------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, Convert const &convert) {
	std::cout << "char: "; convert.displayToChar();
	std::cout << "int: "; convert.displayToInt();
	std::cout << "float: "; convert.displayToFloat();
	std::cout << "double: "; convert.displayToDouble();
	return os;
}

//--------------------------------------------------------//

Convert::Convert()
	: mActualChar(NULL), mActualInt(NULL), mActualFloat(NULL), mActualDouble(NULL) {
	} 

Convert::Convert(const Convert& src)
	: mActualChar(NULL), mActualInt(NULL), mActualFloat(NULL), mActualDouble(NULL) {
	(*this) = src;
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src) {
		delete mActualChar; mActualChar = NULL;
		delete mActualInt; mActualInt = NULL;
		delete mActualFloat; mActualFloat = NULL;
		delete mActualDouble; mActualDouble = NULL;

	if (src.mActualChar != NULL)
		mActualChar = new char(*(src.mActualChar));
	if (src.mActualInt != NULL)
		mActualInt = new int(*(src.mActualInt));
	if (src.mActualFloat != NULL)
		mActualFloat = new float(*(src.mActualFloat));
	if (src.mActualDouble != NULL)
		mActualDouble = new double(*(src.mActualDouble));
	}
	return *this;
}
