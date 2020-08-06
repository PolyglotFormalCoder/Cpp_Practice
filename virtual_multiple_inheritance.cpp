#include <iostream>
#include <memory>
class A
{
public:
    virtual void setdata(){};
     ~A()
    {
                std::cout << "Destructor A" << std::endl;

    };
};

class B : public A
{
public:
    B()
    {
        std::cout << "Constructor B" << std::endl;
    }
     void setdata()
    {
        std::cout << "Set data Class B" << std::endl;
    }
    ~B()
    {
        std::cout << "Destructor B" << std::endl;
    }
};

class C : public B
{
public:
   C()
    {
        std::cout << "Constructor C" << std::endl;
    }
    void setdata()
    {
        std::cout << "Set data Class C" << std::endl;
    }
    ~C()
    {
        std::cout << "Destructor C" << std::endl;
    }
};


int main()
{
    A* a = new C();
    a->setdata();
    delete a;
    
};