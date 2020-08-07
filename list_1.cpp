#include <iostream>
#include <list>
#include <iterator>


void print(std::list<int>& vec1)
{
    std::cout<<"printing: ";
    for (auto x : vec1)
   {
       std::cout<<x<<"  ";
   }
   std::cout<<std::endl;
}

int main()
{
   std::list<int> vec1 ={1,2,3,4,5};
   print(vec1);
   vec1.push_back(100);
   print(vec1);
   vec1.pop_back();
   print(vec1);
   vec1.push_front(0);
   print(vec1);
   vec1.pop_front();
   print(vec1);
   std::cout<<"size: "<<vec1.size()<<" max size: "<<vec1.max_size();
   //std::cout<<" capacity: "<<vec1.capacity();
   if(vec1.empty())
   {
       std::cout<<" list is empty";
   }
   //vec1.reserve(23058);
   //std::cout<<" capacity: "<<vec1.capacity()<<std::endl;
   std::cout<<vec1.front()<<std::endl;
   std::cout<<vec1.back()<<std::endl; 
   for (auto it = vec1.begin(); it != vec1.end(); ++it)
   {
       std::cout<<*it;
   }
   std::cout<<std::endl;  
   vec1.insert(vec1.end(),500);
   print(vec1);
   vec1.emplace(vec1.end(),700);
    print(vec1);
    vec1.emplace_back(1700);
    print(vec1);
    std::list<int> vec2 ={10,20,30,40,50};
    vec2.swap(vec1);
    print(vec1);
    print(vec2);
    vec2.clear();
    print(vec2);
    std::list<int, std::allocator<int>>* vec_pointer = new std::list<int>();
    (*vec_pointer).push_back(100);
    delete vec_pointer;
}
