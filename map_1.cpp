#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> map1 = {
        {1, "ONE"},
        {1, "one"},
        {2, "TWO"},
        {3, "THREE"}
    };

    map1.emplace(4, "FOUR");
    map1.insert(std::pair<int, std::string>(5, "FIVE"));    
    for (auto it = map1.crbegin(); it != map1.crend(); ++it)
    {
        std::cout<<it->first<<"  "<<it->second<<std::endl;
    }   
    std::cout<<"count: "<<map1.count(1)<<std::endl;
    map1.clear();
     for (int i =0; i < map1.size(); i++)
    {
        std::cout<<map1[i]<<std::endl;
    }
     map1.emplace(100, "HUNDRED");
     auto it = map1.find(100);
     std::cout<<it->second<<std::endl;
     map1.emplace(101, "HUNDREDONE");
     map1.emplace(102, "HUNDREDTWO");
     map1.emplace(103, "HUNDREDTHREE");
    auto itlow=map1.lower_bound (100); 
    std::cout<<itlow->first<<"  "<<itlow->second<<std::endl;
    auto itup=map1.upper_bound (102); 
    std::cout<<itup->first<<"  "<<itup->second<<std::endl;
    return 0;
}