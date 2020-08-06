#include<iostream>
template<typename TT>
TT fun(TT x)
{
    x = x+1;
    return x;
}
int main()
{
   std::cout<<fun(2)<<std::endl;
   std::cout<<fun(21.2)<<std::endl;
   std::cout<<fun('c')<<std::endl;
   std::cout<<fun("fdfd")<<std::endl;
}