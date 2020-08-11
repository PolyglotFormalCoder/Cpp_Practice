#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> vector_1 = {100,100, 100,100,200,300,400};
    auto counter = std::count(vector_1.begin(), vector_1.end(), 100);
    std::cout<<"counter value is: "<<counter<<std::endl;   
    std::vector<std::string> vector_2 = {"aa","aa","aa","b","c"}; 
    auto counter_2 = std::count(vector_2.begin(), vector_2.end(), "aa");
    std::cout<<"counter value is: "<<counter_2<<std::endl;
    return 0;
}