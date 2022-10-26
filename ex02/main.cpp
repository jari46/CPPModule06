#include <iostream>
#include <cstdlib>//srand, rand
#include "Class.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
	Base *whoAmI = generate();
	std::cout << "you are "; identify(whoAmI);

	Base *whoAmI2 = generate();
	std::cout << "you are "; identify(*whoAmI2);

	delete whoAmI;
	delete whoAmI2;
}

Base *generate(void) {
		srand(time(NULL));
		switch (std::rand() % 3) {
			case 0 :
				std::cout << "A is returned" << std::endl;
				return new A;
			case 1 :
				std::cout << "B is returned" << std::endl;
				return new B;
			case 2 :
				std::cout << "C is returned" << std::endl;
				return new C;
			default :
				return NULL;
		}
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
			(void)dynamic_cast<A &>(p);
			std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
			(void)dynamic_cast<C &>(p);
			std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}
