#include<iostream>
int main()
{
   const int x =100;   
   const int* y = &x;
   int *z;
   z = const_cast<int *>(y);
   *z =101;
   std::cout<<x<<"  "<<&x<<std::endl;
    std::cout<<*y<<"  "<<y<<std::endl;
   std::cout<<*z<<"  "<<z<<std::endl;
}