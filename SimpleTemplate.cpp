//simple template
#include<iostream> 
#include<vector>
using namespace std; 

template<typename N>
N x;
template<typename T>
T func (T a)
{
    return a;
}
template<typename T>
static T y;

int func(int b)
{
    std::cout<<"special function "<<b<<std::endl;
    return b;
}
/*
int func(double b)
{
    std::cout<<"special function "<<b<<std::endl;
    return b;
}
*/


int main() 
{ 
	
    std::cout<<func<int>(100)<<std::endl;
    std::cout<<func<char>('a')<<std::endl;
    std::cout<<func<std::string>("hello")<<std::endl;
    func<std::vector<int>>({1,2,3});
    func<std::vector<std::string>>({"a","b"});
    x<int> = 3;
    func(x<int>);
    std::cout<<func(3.34)<<std::endl;
    y<double> = 2.222;
    std::cout<<func(y<double>)<<std::endl;
	return 0; 
} 
