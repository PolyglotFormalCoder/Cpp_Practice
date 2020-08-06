#include <iostream>
class base
{
public:
base(int x):var1(x)
{
    std::cout<<"base class constructed"<<std::endl;
}
~base()
{
    std::cout<<"base class destroyed"<<std::endl;
}
private:
int var1;
};
class derived
{
public:
derived(int x, int y):var2(x), b{y}
{
    std::cout<<"derived class constructed"<<std::endl;
}
derived():var2(0), b{0}
{
    std::cout<<"derived class default constructor constructed"<<std::endl;
}
~derived()
{
    std::cout<<"derived class destroyed"<<std::endl;
}
private:
int var2;
base b;
};

int main()
{
    derived d2 {1,2};
    derived d3;
}

