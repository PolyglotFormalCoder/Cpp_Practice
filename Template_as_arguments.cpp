//simple template
#include<iostream> 
#include<vector>
#include <cstddef>
#include <concepts>
#include <functional>
using namespace std; 
template <typename T>
class Node
{
public:
Node(T temp):x(temp){}
T operator()() { return x;}
private:
T x;
};
template<typename T, template<typename> class Node>
class Closure
{
public:
Closure(T t, Node<T> temp): m(t), y(temp){}
T getTotal()
{
    return (m + y());
}
private:
T m;
Node<T> y;
};
template<typename T>
  using NODE = Node<int>;

int main()
{
    Node<int> n(200);
    std::cout<<"Node value: "<<n()<<std::endl;
    Closure<int, NODE> c(300, n);
    std::cout<<"Closure value: "<<c.getTotal();
    return 0;
}