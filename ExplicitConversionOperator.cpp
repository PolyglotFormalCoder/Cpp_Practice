#include <iostream> 
#include <vector>
#include<complex>
#include<memory>
using namespace std;


int main()
{
std::unique_ptr<int> ptr = std::make_unique<int>();
bool result =  static_cast<bool>(ptr);
//bool result =  ptr; //does not work since explicit operator bool() const noexcept;
if (result)
{
    std::cout<<"created";
}

}