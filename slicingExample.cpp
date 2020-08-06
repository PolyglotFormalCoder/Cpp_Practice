#include <iostream> 
#include <vector>
using namespace std; 

struct Base {
    int b;
    Base(const Base& org) = delete;
    Base(int x): b{x}
    {}
};
struct Derived : Base {
    int d;
    Derived(const Derived& org): d{org.d}, Base{org.b}
    {}
    Derived(int x): d{x}, Base{0}  
    {}
};
void naive(Base* p)
{
    Base b2 = *p; // may slice: invokes Base::Base(const Base&)
}
void user()
{
    Derived d{100};
    naive(&d);
    Base bb = d; // slices: invokes Base::Base(const Base&), not Derived::Derived(const Derived&)

}

int main() 
{ 
    user();
} 
