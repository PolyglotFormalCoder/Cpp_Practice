//simple template
#include<iostream> 
#include<vector>
using namespace std; 
template<typename U>
class Y;

template<typename T>
class X
{
    public:
    template<typename U>
    T get(T data, Y<U>& y)
    {
        std::cout<<y.data<<std::endl;
        return data;
    }
};

template<typename U>
class Y
{
    private:
    U data;
    public:
    Y(U temp):data(temp){}
    U get()
    {
        return data;
    }
    template<typename T>
    friend class X;
};

int main() 
{ 
    Y<double> y{2.22};
    X<int> x;
    std::cout<<x.get(100, y);
    
} 
