//experiment to differentiate b/w copy and reference
#include <iostream>
int main()
{
int v[] = {0,1,2,3,4,5,6,7,8,9};
for (auto &x : v) // for each x in v
{
std::cout << x << '\n';
x = x+50;
}
std::cout <<std::endl;
for (auto &x : v) // for each x in v
{
std::cout << x << '\n';
}
return 0;
}