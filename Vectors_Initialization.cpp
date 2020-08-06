//copy and move vectors
//use copy constructors, move constructors, copy operator, move operator
#include <iostream>
#include <vector>
class VectorHandle
{
public:
    //constructor
    VectorHandle(const std::vector<int>& vec_temp) : vec(vec_temp) 
    {      
        std::cout<<"Vector constructed"<<std::endl;
    }
     //copy constructor
    VectorHandle(const VectorHandle& vec_temp) : vec(vec_temp.vec) 
    {      
        std::cout<<"Vector copy constructed"<<std::endl;
    }
    //copy assignment operator
    void operator=(const VectorHandle& vec_temp)
    {
        vec = vec_temp.vec;
        std::cout<<"copy assignment operator called"<<std::endl;
    }
    //move assignment operator
    void operator=(VectorHandle&& vec_temp)
    {
        vec = vec_temp.vec;
        vec_temp.vec.clear();
        std::cout<<"move assignment operator called"<<std::endl;
    }
    //Display vector
    void DisplayVector()
    {
        std::cout<<"Displaying vector:";
        for (int index=0; index< vec.size(); index++)
        {
            std::cout<<vec[index]<<" ";
        }
        std::cout<<std::endl;
    }
private:
std::vector<int> vec;
};

int main()
{
    std::vector<int>vec {1,2 ,3, 4,5 };
    VectorHandle VH1(vec);
    VH1.DisplayVector();
    VectorHandle VH2(VH1);
    VH2.DisplayVector();
    VH2= VH1;
    VH1.DisplayVector();
    VH2.DisplayVector();
    VH2= std::move(VH1);
    VH1.DisplayVector();
    VH2.DisplayVector();
    return 0;
}
