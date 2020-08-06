#include <iostream> 
#include <vector>
using namespace std; 


class Base
{
    public:
    Base(int *address):p(address)
    {
        std::cout<<"inside Base1"<<std::endl;
    }
   Base& operator=(const Base& RHS)
   {
       // *p = *RHS.p;     //deep copy   
       p = RHS.p;          //shallow copy
       return *this;
    }
    void ChangeValue(int x)
    {
        *p = x;
    }
    void display()
    {
        std::cout<<"value of *P: "<<*p<<std::endl;
    }
    private:
    int *p;
};



int main() 
{ 
    Base b1{new int{333}};
    Base b2{new int{999}};
    b1.display();
    b2.display();
    b1 = b2;    
    b1.ChangeValue(555);
    b1.display();
    b2.display();
	return 0; 
} 
