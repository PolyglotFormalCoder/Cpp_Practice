#include<initializer_list>
#include<iostream>
template<int X>
void func(int (&&r)[X])
{
   std::cout<<X;
}

int main()
{
    func({1,2,4,300});
}