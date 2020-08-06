#include<iostream>
#include<vector>
#include<functional>
void fun(int x, int& p)
{
    //x++;    
    std::cout<<x+p<<std::endl;
}

int main()
{
   int x =100;
   auto Lam = [=](int p) mutable
   {
       p++;
       fun(x,p);
       std::function<void(void)> Lam2 = [&Lam2](){std::cout<<"hello";};
       Lam2();
    };
    //std::vector<std::function<void(int)>> vec1 = {Lam, Lam};    
    std::vector<std::function<void(int)>> vec1 = {Lam, Lam}; 
   //Lam(10);
   //Lam(10);
   vec1[0](10);
   std::vector<std::function<void(int, int&)>> vec2 = {fun, fun};  
   int o = 200;
   vec2[0](1, o);
}