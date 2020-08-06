#include <iostream> 
#include <vector>
using namespace std; 

int func(int x)
{
    std::cout<<"inside func"<<std::endl;
    return x*x;
}

class Base1
{
    public:
    Base1()
    {
        std::cout<<"inside Base1"<<std::endl;
    }
};

class Base2: public Base1
{
    public:
    Base2(int x):a{func(x)}, Base1{}
    {
        std::cout<<"inside Base2"<<std::endl;
    }
    private:
    int a;
};

class Derived: public Base2
{
    public:
    Derived(int x):Base2{x} {}
    
};


int main() 
{ 
    Derived d{10};
	return 0; 
} 
