#include <iostream> 
#include <vector>

using namespace std; 



int increment(int x)
{
    return x;
}
void transform (std::vector<int>& vec, int (*x)(int))
{
   for (int index=0; index < vec.size(); index++)
        vec[index] = vec[index] + (*x)(100);   
}


int main()
{
    std::vector<int> vec ={1,2 ,3, 4,5};
    transform(vec, increment);

    for (int index=0; index < vec.size(); index++)
        std::cout<<vec[index]<<std::endl;
}