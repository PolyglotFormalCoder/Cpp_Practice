#include <iostream>
class base1
{
public:
base1(int x):b1(x)
{
    std::cout<<"base1 constructed"<<std::endl;
}

private:
int b1;

};

class base2: public base1
{
public:
base2(int x, int y):b2(x),base1{y}
{
    std::cout<<"base2 constructed"<<std::endl;
}
private:
int b2;
};

class derived: public base2
{
public:
derived(int x, int y, int z):d1(x), base2(y,z)
{
    std::cout<<"derived constructed"<<std::endl;
} 

private:
int d1;
};

int main()
{
    derived d {10, 20, 30};
    return 0;
}