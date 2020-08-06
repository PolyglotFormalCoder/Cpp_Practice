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
    virtual ~A(){std::cout<<"A destructed"<<std::endl;}
    virtual void display()=0;
    private:
    int a;
};

class B: public A
{
    public:
    B(){std::cout<<"Default B contructed"<<std::endl;}
    B(int x):b(x), A(0)
    {std::cout<<"B contructed"<<std::endl;}
    virtual ~B(){std::cout<<"B destructed"<<std::endl;}
    void display() {std::cout<<"displaying B"<<std::endl;}
    private:
    int b;
};

class C: public A
{
    public:
    C(){std::cout<<"Default C contructed"<<std::endl;}
    C(int x):b(x), A(0)
    {std::cout<<"C contructed"<<std::endl;}
    virtual ~C(){std::cout<<"C destructed"<<std::endl;}
    void display() {std::cout<<"displaying C"<<std::endl;}
    private:
    int b;
};

// factory
class Factory
{
public:
Factory(){}
A* CreateB(int x)
{
    Btype = new B(x);
    return Btype;
}

A* CreateC(int x)
{
    Ctype = new C(x);
    return Ctype;
}
~Factory()
{
    delete Btype;
    delete Ctype;
    std::cout<<"destroyed B and C"<<std::endl;
}
private:
A* Btype;
A* Ctype;
};


int main()
{
    Factory f;
    A* b = f.CreateB(100);
    b->display();
    A* c = f.CreateC(10);
    c->display();
}
