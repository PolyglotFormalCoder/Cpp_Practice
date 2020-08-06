#include <iostream> 
#include <vector>

using namespace std;
class Disp
{
public:
	virtual void func()
	{
		std::cout << "Disp" << std::endl;
	}

};
class DispMore : public Disp
{
public:
	void func()
	{
		std::cout << "DispMore" << std::endl;
	}

};

class VectorVector
{
public:
	VectorVector(std::vector<std::vector<int>> temp, Disp x) :VecVec(temp), disp(&x)
	{

	}
	void Display()
	{
		std::cout << "Displaying vector: ";
		for (const auto& inner : VecVec)
			for (const auto& x : inner)
				std::cout << x;
		std::cout << std::endl;
	}
	int operator()(int x, int y)
	{
		return VecVec[x][y];
	}
	/*  VectorVector* operator->()
	  {
		  return this;
	  }*/
	Disp* operator->()
	{		
		disp = nullptr; //this is needed otherwise return doesnt matter
		return disp;
	}
private:
	std::vector<std::vector<int>> VecVec;
	Disp *disp;

};


int main()
{
	std::vector<std::vector<int>> temp = { {1,2},{3,4} };
	Disp disp;
	VectorVector vec{ temp,disp };
	vec.Display();
	vec->func(); //-> can be overloaded to return object pointer
	std::cout << "Overloading (): " << vec(1, 1);

}