#include <iostream>
#include <exception>
int main()
{
    try
    {       
        std::domain_error e1 = std::domain_error("error");
        throw e1;
    }
    catch(std::exception& e)
    {
        std::cout<<e.what();
    }
    catch(...)
    {
        std::cout<<"undefined exception caught";
    }
    return 0;
}