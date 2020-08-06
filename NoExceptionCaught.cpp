#include <iostream>
#include <cmath>
using namespace std;

void Fun1() noexcept
{
    throw std::runtime_error("unknown error");
}

int main()
{
    try
    {
        Fun1();
    }
    catch(std::exception& e)
    {
        std::cerr<<"exception caught"<<e.what();
    }

}