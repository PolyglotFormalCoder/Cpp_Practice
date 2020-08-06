// C++ program to demonstrate 
// alignof vs sizeof operator 
#include <iostream> 
#include <array>
using namespace std; 

class Apple
{
    public:
    Apple(int a):x(a)
    {}
    Apple (const Apple& temp)
    {
        x = temp.x;
    }
    Apple (Apple&& temp)
    {
        x = temp.x;
        temp.x =0 ;
    }
    int get_data() 
    {
        return x;
    }        
    void operator=(const Apple &temp)
    {
       x = 55;
    }
    void operator=(Apple &&temp)
    {
       x = temp.x;
       x=0;
    }
    private:
    int x;
};
  
int main()
{
    Apple apple_1(20), apple_2(30);
    Apple apple_3 = apple_1;
    Apple appl_4 = std::move(apple_3);
    apple_1 = apple_2;
    apple_1 = std::move(apple_2);
    std::cout<<apple_1.get_data();

}