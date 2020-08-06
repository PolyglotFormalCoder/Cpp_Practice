#include <iostream> 
#include <vector>

using namespace std;
class complex 
{
double re;
public:
complex(double r) :re{r}{ } // build a complex from a double
/* does not work for 2.0+a;
complex operator+(complex second)
{
    complex result{0.0};
    result.re = re + second.re;
    return result;
}
*/
friend complex operator+(complex first, complex second);
};


complex operator+(complex first, complex second)
{
    complex result{0.0};
    result.re = first.re + second.re;
    return result;
}


int main()
{
    complex a{3.0};
    complex b {2.0};
    complex c {0.0};
    c = a+b;
    c = 2.0+a;
    c = a+3.0;
    return 0;
}