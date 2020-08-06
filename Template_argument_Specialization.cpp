//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
using namespace std; 
template <typename T, int N>
class C
{
public:
C(T temp):a(temp){}
T operator()(){
    std::cout<<"generic: "<<N<<std::endl;
    return a;}
private:
T a;
};

template <typename T>
class C <T,0>
{
public:
C(T temp):a(temp){}
T operator()(){
    std::cout<<"generic 0 case: "<<0<<std::endl;
    return a;}
private:
T a;
};

int main()
{
    C<int,100> c(2000);   
    C<int,0> d(2000);
    std::cout<<c()<<std::endl;   
    return 0;
}