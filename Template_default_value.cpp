//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
using namespace std; 
template <typename T, T  default_value>
T func(T input)
{
    std::cout<<input+default_value;
    return (input+default_value);
}

int main()
{
    func<int,50>(30);
    return 0;
}