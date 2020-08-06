#include <iostream>
class OperatorTest
{
    public:
    OperatorTest(int temp):a(temp)
    {}
 OperatorTest& operator+=(OperatorTest& o1)
    {      
        a = a + o1.a;
        std::cout<<"Single parameter is invoked: "<<a<<std::endl;
        return *this;
    } 
    
    void Display()
    {
        std::cout<<"Result: "<<a<<std::endl;
    }
    friend OperatorTest operator+(const OperatorTest& o1, const OperatorTest& o2);
    private:
    int a;

};
 
int main()
{
    OperatorTest o1 {2};
    OperatorTest o2 {3};
    o2 += o1 ;
    o2.Display();
}