#include <iostream>
class Animal
{
    public:
    explicit Animal(int x, double y):a(x), f(y)
    {
        std::cout<<"calling constructor"<<std::endl;
    }
    Animal(Animal& ani) = delete;
    void operator=(Animal& ani) = delete; 
    Animal(Animal&& ani)
    {
        a = ani.a;
        f = ani.f;   
        std::cout<<a<<f;    
    }

private: 
int a;
double f;
};

int main()
{
    Animal ani = Animal{1, 2.0};
    Animal ani2 = std::move(ani);
    return 0;
}