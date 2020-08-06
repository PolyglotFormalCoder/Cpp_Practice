#include <iostream> 
#include <vector>
#include <complex>  
class B;
class A
{
    public:
A(int x):a(x)
{}
void display(B&);
private:
int a;
};

class B
{
    public:
B(int y):b(y)
{}
friend void A::display(B&);
private:
int b;
};

void A::display(B& b)
{
    std::cout<<"a: "<<a<<" b: "<<b.b<<std::endl;
}
int main()
{
    A a(100);
    B b{200};
    a.display(b);
}