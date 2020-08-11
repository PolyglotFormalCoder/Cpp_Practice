#include <iostream>
#include <vector>
#include <algorithm>
void increment(int& x) {  x++; } 

int main()
{
    std::vector<int> vector_1 = {1,2,3,4};
    std::for_each(vector_1.begin(), vector_1.end(), increment);
    for(auto x : vector_1)
    {
        std::cout<<x<<" ";
    }
    return 0;
}