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
T getData();
private:
T a;
};

template <typename T, int N>
T C<T, N>::getData()
{
    return a;
}

int main()
{
    C<int,100> c(2000);  
    std::cout<<c()<<std::endl;   
    return 0;
}