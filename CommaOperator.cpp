#include <iostream>
int func();
int main()
{
    int x = 4;
    int y = 0;
    int z = 0;
    int m = 501;
    int n = 502; 
    int p = 89;
    z = (x, m,n,func());
    
    std::cout << z  << '\n';
}

int func()
{
    return 101;
}