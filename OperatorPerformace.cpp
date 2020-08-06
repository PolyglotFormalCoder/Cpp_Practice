#include<string>
#include<iostream>
/* Reference from stack overflow:
The standard correctly defines the return type of an assignment operator. 
Actually, the assignment operation itself doesn't depend on the return value - that's why the return type isn't straightforward to understanding.
The return type is important for chaining operations. Consider the following construction: a = b = c;. 
This should be equal to a = (b = c), i.e. c should be assigned into b and b into a. Rewrite this as a.operator=(b.operator=(c)).
In order for the assignment into a to work correctly the return type of b.operator=(c) must be reference to the inner assignment result (it will work with copy too but that's just an unnecessary overhead).
The dereference operator return type depends on your inner logic, define it in the way that suits your needs.
*/


class Example
{
public:
	Example() {};
	//Example: Implementation of the unique pointers 
	//Example(Example const& other) = delete;
	Example(Example const& other)
	{
		index = other.index;
	}
	Example& operator=(const Example& other)
	{
		Example ex;
		this->index = other.index;
		return ex;
	}
	int getIndex()
	{
		return index;
	}
	void setIndex(int Index)
	{
		index = Index;
	}
private:
	int index;

};

int main()
{
	Example *e1 = new Example;
	e1->setIndex(2);
	int output;
	output = e1->getIndex();	
	std::cout << e1->getIndex();
	
	Example e2 = *e1;

	e2.setIndex(20000);
	std::cout << "address e1 points to is" << e1<<std::endl;
	*e1 = e2;
	std::cout << "address of e1 after copy" << e1 << std::endl;
	std::cout << "e1 index:" << e1->getIndex() << "e2 index:" << e2.getIndex() << std::endl;
}