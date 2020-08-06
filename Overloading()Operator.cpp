#include <iostream> 
#include <vector>

using namespace std; 

class VectorVector
{
    public:
    VectorVector(std::vector<std::vector<int>> temp):VecVec(temp)
    {}
    void Display()
    {
        std::cout<<"Displaying vector: ";
        for(const auto& inner: VecVec)
            for(const auto& x: inner)
                std::cout<<x;
        std::cout<<std::endl;
    }
    int operator()(int x, int y)
    {        
        return VecVec[x][y];
    }
    private:
    std::vector<std::vector<int>> VecVec;
    
};


int main()
{
    std::vector<std::vector<int>> temp = {{1,2},{3,4}};
    VectorVector vec{temp};
    vec.Display();
    std::cout<<"Overloading (): "<<vec(1,1);

}