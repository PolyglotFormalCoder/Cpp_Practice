#include <iostream>
#include <cmath>
using namespace std;
int* Fun(int* INPUT)
{
    if (INPUT == NULL)
    {
        throw std::runtime_error("bad alloc");
    }
    return INPUT;
}
class Simple
{    
    public:
    Simple(int* Q):P{Fun(Q)}
    {

    }    
    void print()
    {
        std::cout<<"object created"<<std::endl;
    }
    private:
    int* P;
};
int main()
{
    int x =100;
    //int* LOCAL = nullptr;
    int* LOCAL = &x;
try
{
    Simple s(LOCAL);
    s.print();
}
catch (std::exception& e)
{
    std::cerr<<e.what();    
}

}