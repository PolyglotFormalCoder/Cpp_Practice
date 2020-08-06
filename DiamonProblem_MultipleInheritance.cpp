#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class A
{
    public:
    A(){std::cout<<"Default A contructed"<<std::endl;}
    A(int x):a(x)
    {std::cout<<"A contructed"<<std::endl;}
    ~A(){std::cout<<"A destructed"<<std::endl;}
    private:
    int a;
};

class B: public virtual A
{
    public:
    B(int x,int y):b(x),A(y){std::cout<<"B contructed"<<std::endl;}
    ~B(){std::cout<<"B destructed"<<std::endl;}
    private:
    int b;
};

class C: public virtual A
{
    public:
    C(int x, int y):c(x), A(y){std::cout<<"C contructed"<<std::endl;}
    ~C(){std::cout<<"C destructed"<<std::endl;}
    private:
    int c;
};

class D: public C, public B
{
    public:
    D(int x, int y, int z):d(x), C(y,z), B(y,z), A(z){std::cout<<"D contructed"<<std::endl;}
    ~D(){std::cout<<"D destructed"<<std::endl;}
    private:
    int d;
};



int main()
{
   D d(10,20,30);
}
