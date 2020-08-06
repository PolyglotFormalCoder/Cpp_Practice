#include<iostream>
template <typename T>
class Temp1
{
    T x;
    inline static int yy = 55;
    static const int q = 0;
    public:
    Temp1(T t);
    T Add(T x1, T x2);
    Temp1& operator+(Temp1 t);    
};
template <typename T>
Temp1<T>::Temp1(T t):x(t)
{    
    yy++;
    std::cout<<"value of yy:"<<yy<<std::endl;
}
template <typename T>
T Temp1<T>::Add(T x1, T x2)
{
    return x1+x2+x;
}
template <typename T>
Temp1<T>& Temp1<T>::operator+(Temp1 t)
{

}
int main()
{
    Temp1<int> t1(34);
    std::cout<<t1.Add(23, 232);
    Temp1<int> t2(50);
    Temp1<float> t3(50.22);
}