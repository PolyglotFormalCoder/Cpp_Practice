#include <iostream>
class Name
{
public:
static void getData(int & x)
{
x++;
}
};
class Animal
{
    public:
    void getName() const
    {
        Name::getData(a);
    }

private: 
mutable int a=0;
double f;
};



int main()
{
    
    return 0;
}