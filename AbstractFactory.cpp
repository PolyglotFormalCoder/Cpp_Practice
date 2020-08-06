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

// abstract factory
class AbstractFactory
{
public:
AbstractFactory(){}

virtual A* Create(int x)=0;

virtual ~AbstractFactory() {};

protected:
A* type;

};

class BFactory : public AbstractFactory
{    
public: 
BFactory(){}
A* Create(int x) 
{
    type = new B(x);
    return type;
}
~BFactory ()
{
    delete type;
    std::cout<<"destructor BFactory"<<std::endl;
}


};

class CFactory : public AbstractFactory
{
public: 
CFactory(){}
A* Create(int x)
{
    type = new C(x);
    return type;
}
~CFactory ()
{
    delete type;
    std::cout<<"destructor CFactory"<<std::endl;
}

};

int main()
{
    BFactory f;
    A* b = f.Create(100);
    b->display();
    CFactory g;
    A* c = g.Create(10);
    c->display();
}
