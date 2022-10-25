#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert {
	private:
		char *mActualChar;
		int *mActualInt;
		float *mActualFloat;
		double *mActualDouble;

		Convert();/* no use*/

	public:
		Convert(char *input);
		Convert(const Convert& src);
		Convert& operator=(const Convert& src);
		~Convert();

		void displayToChar() const;
		void displayToInt() const;
		void displayToFloat() const;
		void displayToDouble() const;
};

std::ostream &operator<<(std::ostream &os, Convert const &b);

#endif //CONVERT_HPP