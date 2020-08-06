#include <iostream> 
#include <vector>

class Experiment
{
public:
Experiment(int x):a(x)
{}

Experiment& operator++()
{
    ++a;
    return *this;
}

Experiment operator++(int incr)
{
    Experiment temp{0};
    temp.a = a++;
    return temp;
}
void display()
{
    std::cout<<"output: "<<a<<std::endl;
}

private:
int a;
};

int main()
{
   Experiment exp{100};
   ++exp;
   exp.display();
   exp++;
   exp.display();
   int x=0;
   std::cout<<x<<" "<<x++<<" "<<++x<<std::endl;
}