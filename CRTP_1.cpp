//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
#include <chrono> 
using namespace std; 
typedef std::chrono::high_resolution_clock Clock; 

struct Bla
{
    int var[100000];
    int var2[100000];
    int var3[100000];
    string L;
};

template <typename T>
class Base
{
    public:
    Base()
    {

    }
    void getData() 
    {
        static_cast<T*>(this)->getData();
    }   
    protected:
    int data;
    Bla bl;
};

class Derived : public Base<Derived>
{
   public:
   void getData()
   {
       std::cout<<data;
   }
};

class Base1
{
    public:
    Base1()
    {

    }
    virtual void getData() = 0;
  
    protected:
    int data;   
    Bla bl; 
};
class Derived1 : public Base1
{
   public:
   void getData()
   {
       std::cout<<data;
   }
};

int main()
{   
    Base<Derived>*b = new Derived;
    // Store time after virtual function calls 
    auto then = Clock::now(); 
    for (int i = 0; i < 10000; ++i) 
     b->getData();
    // Store time after virtual function calls 
    auto now = Clock::now(); 
    cout<< std::endl;
    cout << "Time taken for CTRP calls: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count() 
         << " nanoseconds" << endl; 
  
    Base1* b1 = new Derived1;
    // Store time after virtual function calls 
    auto then1 = Clock::now(); 
    for (int i = 0; i < 10000; ++i) 
     b1->getData();
    // Store time after virtual function calls 
    auto now1 = Clock::now(); 
    cout<< std::endl;
    cout << "Time taken for virtual calls: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(now1 - then1).count() 
         << " nanoseconds" << endl; 
    return 0;
}