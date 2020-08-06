#include <iostream> 
#include <vector>
#include<complex>
using namespace std;


class Tiny {
char v;
void assign(int i) { if (i == 0) throw Bad_range(); v=i; }
public:
class Bad_range { };
Tiny(int i) { assign(i); }
Tiny& operator=(int i) { assign(i); return *this; }
operator int() const { 
    std::cout<<"conversion happened"<<std::endl;
    return v; } // conversion to int function
};

int main()
{
Tiny c1 = 2;
Tiny c2 = 62;
auto i = c1+c2; // i = 64
}