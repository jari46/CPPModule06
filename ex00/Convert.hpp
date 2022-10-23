#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>


class Convert {
	private:
		double mInput;
		char *mEndptr;

		int	getCastingToInt() const;
		float	getCastingToFloat() const;
		double	getCastingToDouble() const;

		Convert();

	public:
		Convert(std::string input);
		Convert(const Convert& src);
		Convert& operator=(const Convert& src);
		~Convert();

		void displayToInt() const;
		void displayToFloat() const;
		void displayToDouble() const;
		
		double getInput() const;
		char *getEndptr() const;

};

std::ostream &operator<<(std::ostream &os, Convert const &b);

#endif //CONVERT_HPP