#include <iostream>
#include <vector>
#include <map>

class MyVectorPair
{

public:
MyVectorPair(const std::vector<int>& k,const std::vector<int>& v):key{k}, value{v}
{
   for (int index=0; index<k.size(); index++)
   {
       my_map[k[index]] = value[index];
   }
}

int operator[](const int one_key)
{
    std::map<int,int>::iterator it = my_map.find(one_key);    
    if(it != my_map.end())
    {
    //element found;
        return it->second;
    }   
    else
        return -1;
}


private:
std::vector<int> key;
std::vector<int> value;
std::map<int, int> my_map;
};

int main()
{
    std::vector<int> key = {1,2,3};
    std::vector<int>value = {100,200,300};

    MyVectorPair mvp(key,value);
    
    std::cout<<mvp[key[0]]<<mvp[key[1]]<<mvp[key[2]] <<mvp[1000];

    


}