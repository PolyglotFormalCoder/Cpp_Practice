//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
using namespace std; 
template <typename T, typename V, typename Op>
V sum(T ini, T last, V org, Op O)
{
    V sum = org;
    while(ini != last)
    {        
        sum=O(sum, *ini);
        ini++;
    }
    return sum;
}
int main()
{
    int x1[] = {1,2,3,4,5,6,67};
    int result = sum<int[], int, std::plus<int>>(x1, x1+7, 0, std::plus<int>());
    std::cout<<"int addition:  "<<result<<std::endl;

    double x2[] = {1.1,2.2,3,4.5,5,6,67};
    double result2 = sum<double[], double, std::plus<double>>(x2, x2+7, 0.0, std::plus<double>());
    std::cout<<"double addition:  "<<result2<<std::endl;
    

    vector<int> x3= {1,2,3,4,5,6,67};
    int result3 = sum<vector<int>::iterator, int, std::plus<int>>(x3.begin(), x3.end(), 0, std::plus<int>());
     std::cout<<"vector int  addition:  "<<result3<<std::endl;
    
    return 0;
}