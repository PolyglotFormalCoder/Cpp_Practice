#include <iostream>
#include <vector>
bool equal(std::string p1, std::string p2)
{
    return (p1==p2);
}


int main ()
{
    std::vector<std::string> vec_1 = {"hello1", "hi", "namaskaram"};
    std::vector<std::string> vec_2 = {"hello", "hi", "namaskaram"};
    if(std::equal(vec_1.begin(), vec_1.end(), vec_2.begin(), equal))
    {
        std::cout<<"vectors are equal";
    }
  std::pair < std::vector<std::string>::iterator, std::vector<std::string>::iterator> pair;
  pair = std::mismatch(vec_1.begin(), vec_1.end(), vec_2.begin(), equal);
  std::cout<<*pair.first<<" "<<*pair.second;

  
  return 0;
}