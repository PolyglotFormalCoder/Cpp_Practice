#include <iostream>
class OperatorTest
{
    public:
    OperatorTest(int temp):a(temp)
    {}
 OperatorTest operator+(OperatorTest& o1)
    {
        OperatorTest result{0};
        result.a = a + o1.a;
        std::cout<<"Single parameter is invoked"<<std::endl;
        return result;
    } 
    
    void Display()
    {
        std::cout<<"Result: "<<a<<std::endl;
    }
    friend OperatorTest operator+(const OperatorTest& o1, const OperatorTest& o2);
    private:
    int a;

};
 OperatorTest operator+(const OperatorTest& o1, const OperatorTest& o2)
    {
        OperatorTest result{0};
        result.a = o2.a + o1.a;
        std::cout<<"Two parameters operator is invoked"<<std::endl;
        return result;
    }
int main()
{
    OperatorTest o1 {2};
    OperatorTest o2 {3};
    OperatorTest o3 = o1 + o2 + OperatorTest(15);
    o3.Display();
}