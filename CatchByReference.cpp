#include <iostream>
#include <cmath>
using namespace std;

class MyErrorCodeBase {
    public:
MyErrorCodeBase(){}
virtual void print() {std:cout<<"print base error code"<<errorCode<<std::endl;}
private:
int errorCode = 50;
};

class MyErrorCode: public MyErrorCodeBase
 {
    public:
MyErrorCode(){}
void print() {std:cout<<"print error code"<<errorCode<<std::endl;}
private:
int errorCode = 100;
};

void Fun1() 
{        
    MyErrorCode d;
    //MyErrorCodeBase* p = &d;
    throw d;
}

int main()
{    
    try
    {
        Fun1();
    }
    catch(MyErrorCodeBase e) //changing it to reference makes it call the derived class
    {
        std::cout<<"exception caught";
        e.print();
    }

}