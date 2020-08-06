#include <iostream>

int& func(int& a, int& b)
{
    return a>b ? a : b;
}

int main()
{
int a = 100;
int b = 200;
int& c = func(a,b);
c = 500;
std::cout<<"c is: "<<c <<" b is :"<<b;

}
