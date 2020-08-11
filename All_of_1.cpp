#include <iostream>
#include <vector>
#include <algorithm>
bool verify(int x) 
{  
    if(x < 100)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

int main()
{
    std::vector<int> vector_1 = {100,200,300,400};
    if(std::all_of(vector_1.begin(), vector_1.end(), verify))
    {
        std::cout<<"All of vector values are less than 100"<<std::endl;
    }
    if(std::any_of(vector_1.begin(), vector_1.end(), verify))
    {
        std::cout<<"Any of vector values are less than 100"<<std::endl;
    }
    if(std::none_of(vector_1.begin(), vector_1.end(), verify))
    {
        std::cout<<"None of vector values are less than 100"<<std::endl;
    }
    for(auto x : vector_1)
    {
        std::cout<<x<<" ";
    }
    return 0;
}