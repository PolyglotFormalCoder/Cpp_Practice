//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
using namespace std; 
template <typename T>
class C
{
public:
C(T temp):a(temp){}
T operator()(){
    std::cout<<"generic"<<std::endl;
    return a;}
private:
T a;
};
template <>
class C<float>
{
public:
C(float temp):a(temp+100.0F){}
float operator()(){
    std::cout<<"specialized"<<std::endl;
    return a;}
private:
float a;
};
int main()
{
    C c(100);
    C d(200.0F);
    std::cout<<c()<<std::endl;
    std::cout<<d()<<std::endl;
    return 0;
}