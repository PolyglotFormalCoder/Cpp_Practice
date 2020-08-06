//simple template
#include<iostream> 
#include<vector>
using namespace std; 

template<typename T>
class Data
{
T mem_1;
T mem_2;
T mem_3;
public:
Data(T x, T y, T z): mem_1(x), mem_2(y), mem_3 (z){}
};

template<typename T, typename U>
class Manip
{
Data<T> data;
U value;
public:

};

int main() 
{ 
	
    
} 
