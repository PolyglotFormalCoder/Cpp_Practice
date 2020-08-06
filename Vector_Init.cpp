
#include <iostream>
#include <vector>
template<typename T>
void f(const std::vector<T>& x1){};
class vectorX
{

public:
	vectorX()
	{
		std::cout << "constructor called"<<std::endl;
	}
	vectorX(const vectorX& v)
	{
		std::cout << "copy constructor called"<<std::endl;
	}

};
int main()
{
	vectorX a, b, c;
	std::vector<vectorX> x{ a, b, c};
    std::vector<int> x1 = {1,2,2};
    f(x1);
    f(std::vector<int>{334,343});
}
