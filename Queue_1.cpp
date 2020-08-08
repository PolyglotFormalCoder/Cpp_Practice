#include <iostream>
#include <queue> //FIFO
int main()
{
   std::queue<int> queue1 ;
   for (int i =0; i < 5; i++)
    queue1.push(i+100);
   for (int i =0; i < 5; i++)
   {
       std::cout<<queue1.front()<<" ";
       queue1.pop();
   }
   std::cout<<queue1.size()<<" ";
   queue1.push(1000);
   std::cout<<"size: "<<queue1.size()<<" "<<std::endl;
   std::cout<<"front: "<<queue1.front()<<" "<<std::endl;
   queue1.push(60);
   queue1.push(70);
   while(queue1.size())
   {
       std::cout<<queue1.front()<<" ";
       queue1.pop();
   }
}
