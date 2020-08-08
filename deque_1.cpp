#include <iostream>
#include <queue>
#include <iterator>


void print(std::deque<int>& deque1)
{
    std::cout<<"printing: ";
    for (auto x : deque1)
   {
       std::cout<<x<<"  ";
   }
   std::cout<<std::endl;
}

int main()
{
   std::deque<int> deque1 ={1,2,3,4,5};
   print(deque1);
   deque1.push_back(100);
   print(deque1);
   deque1.pop_front();
   print(deque1);
   std::cout<<"size: "<<deque1.size()<<" max size: "<<deque1.max_size();  
   if(deque1.empty())
   {
       std::cout<<" deque is empty";
   }
   std::cout<<deque1.front()<<std::endl;
   std::cout<<deque1.back()<<std::endl;
   for (auto it = deque1.begin(); it != deque1.end(); ++it)
   {
       std::cout<<*it;
   }
   std::cout<<std::endl;  
   deque1.insert(deque1.end(),500);
   print(deque1);
   deque1.emplace(deque1.end(),700);
    print(deque1);
    deque1.emplace_back(1700);
    print(deque1);
    std::deque<int> vec2 ={10,20,30,40,50};
    vec2.swap(deque1);
    print(deque1);
    print(vec2);
    vec2.clear();
    print(vec2);
    std::deque<int, std::allocator<int>>* deque_pointer = new std::deque<int>();
    (*deque_pointer).push_front(100);
    delete deque_pointer;
}
