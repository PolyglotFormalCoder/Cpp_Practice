#include<string>
#include<vector>
#include<memory>
#include<iostream>
class Example
{
public:

int getData()
 {
     std::cout<<data<<std::endl;
     std::cout<<data4<<std::endl;
     return data;
 }
/*
Example(Example&& other)
{
    data = other.data;
    data2 = other.data2;
    data3 = other.data3;
    data4 = other.data4;
    other.data = 0;
    other.data2="";
    other.data3={};
    other.data4=NULL;
}
*/
Example():
data(23232),
data2("default"),
data3({0,1,2}),
data4(&data)
{   
}
private:
const int data;
std::string data2;
std::vector<int> data3;
const int* data4; 
};

int main()
{
  // A simple class declaration with simple types, creates constexpr of the default constructor, destructor. 
  // When the class has complex types such as vector, the compiled code has default constructor, destructor 
  Example e1;  
  e1.getData();
  Example e3 = std::move(e1);
  e1.getData();
  e3.getData();
 // std::string st1 = "hello";
 // int *pppi = new int[10];
  
}