#ifndef CLASS_HPP
#define CLASS_HPP

class Base {
	public :
		virtual ~Base() {}
};

class A : public Base {
	public :
		~A() {}
};

class B : public Base {
	public :
		~B() {}
};

class C : public Base {
	public :
		~C() {}
};

#endif // CLASS_HPP