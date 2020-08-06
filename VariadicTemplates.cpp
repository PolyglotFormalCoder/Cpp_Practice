#include <iostream>
int add() 
{
return 0;
}
template <typename T, typename... Types> 
int add(T var1, Types... var2) 
{
int sum = var1 + add(var2...);
return sum;
}

int main()
{
    std::cout<<add(1)<<std::endl;
    std::cout<<add(1,2,3,4,4,45454);
}