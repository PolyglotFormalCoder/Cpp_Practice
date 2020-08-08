#include <iostream>
#include <queue> //FIFO
int main()
{
   std::priority_queue<int,  std::vector<int>, std::greater<int>> queue1 ;
   for(int n : {10,8,5,6,3,4,0,9,7,2})
        queue1.push(n);
   while(!queue1.empty())
   {
       std::cout<<queue1.top()<<" ";
       queue1.pop();
   }
}
