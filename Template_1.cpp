#include <iostream>

template <typename T>
T addition(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << "adding integers:"<<addition(2, 4)<<std::endl;
	std::cout << "adding float:" << addition(2.3, 4.3) << std::endl;
	std::cout << "adding doubale:" << addition(2.54545454, 3.555555555) << std::endl;
  
}

