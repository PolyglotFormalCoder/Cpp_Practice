#include <iostream>
class sample
{
    public:
    sample(int x):c(x), b(c+1), a(b+1){}
    void display()
    {
        std::cout<<"a: "<<a<<" b: "<<b<<" c: "<<c;
    }
    private:
    int a;
    int b;
    int c;

};


int main()
{
    sample s{10};
    s.display();
    return 0;
}