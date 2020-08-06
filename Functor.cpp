#include <iostream>

class Product
{
int a, b;
public:
Product(int x, int y):a(x), b(y)
{}

int operator()(int c, int d)
{
   std::cout<<"operator called";
   return a*b*c*d;
   
}

};


int main()
{

Product(2,3)(5,6);
}
