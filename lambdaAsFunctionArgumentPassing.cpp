#include <iostream>
#include <functional>
void func(std::function<void(void)> P)
{
     P();
}

int main()
{
   int a;
   func([&]{
       a++;
       std::cout<<"hello world"<<std::endl;
   });

}