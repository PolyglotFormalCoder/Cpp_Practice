#include <iostream>
namespace Animals
{
    namespace Canine
    {
        class Tiger
        {
            public:
            void getTiger()
            {
                std::cout<<"Tiger"<<std::endl;
            }
        };

    }
}

int main()
{
    Animals::Canine::Tiger tiger;
    tiger.getTiger();
}
