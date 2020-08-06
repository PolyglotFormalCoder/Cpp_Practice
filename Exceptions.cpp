#include <iostream>
#include <stdexcept>
int main()
{
try 
{
 int div = 0;
 auto x = 1;
 auto result = 0;
 if (div == 0)
        throw std::overflow_error("Divide by zero exception");
 
 result = x/div;
}
catch(std::overflow_error e)
{   
std::cout<<e.what(); 
}

}