#include <iostream>

/*
 * RAIITest Class models RAII behavior that depends on destructor being called when object goes out of scope.
 */
class RAIITest {
public:
	RAIITest() {
		std::cout << "-RAII- constructor" << std::endl;
	}
	~RAIITest() {
		std::cout << "-RAII- destructor" << std::endl;
	}
};

/*
 * Base has a virtual destructor
 */
class Base {
public:
	Base() {
		std::cout << "-Base- constructor" << std::endl;
	}
	//A non-virtual destructor signifies that a class should not be used as a base-class.
	virtual ~Base() {
		std::cout << "-Base- destructor" << std::endl;
	}
};

/*
 * Derived has a RAII class with a destructor defined
 */
class Derived final : public Base {
public:
	RAIITest test;

	Derived() {
		std::cout << "-Derived- constructor" << std::endl;
	}
	

	~Derived()
	{
		std::cout << "-Derived- destructor" << std::endl;
	}
};

int main()
{
	Base *b = new Derived(); 
	//Base b = Derived();	
	delete b;

	//Derived d;
}