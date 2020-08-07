#include <iostream>
#include <list>
#include <iterator>


void print(std::list<int>& list1)
{
    std::cout<<"printing: ";
    for (auto x : list1)
   {
       std::cout<<x<<"  ";
   }
   std::cout<<std::endl;
}

int main()
{
   std::list<int> list1 ={1,2,3,4,5};
   print(list1);
   list1.push_back(100);
   print(list1);
   list1.pop_back();
   print(list1);
   list1.push_front(0);
   print(list1);
   list1.pop_front();
   print(list1);
   std::cout<<"size: "<<list1.size()<<" max size: "<<list1.max_size();
   
   if(list1.empty())
   {
       std::cout<<" list is empty";
   }
  
   std::cout<<list1.front()<<std::endl;
   std::cout<<list1.back()<<std::endl; 
   for (auto it = list1.begin(); it != list1.end(); ++it)
   {
       std::cout<<*it;
   }
   std::cout<<std::endl;  
   list1.insert(list1.end(),500);
   print(list1);
   list1.emplace(list1.end(),700);
    print(list1);
    list1.emplace_back(1700);
    print(list1);
    std::list<int> list2 ={10,20,30,40,50};
    list2.swap(list1);
    print(list1);
    print(list2);
    list2.clear();
    print(list2);
    std::list<int, std::allocator<int>>* vec_pointer = new std::list<int>();
    (*vec_pointer).push_back(100);
    delete vec_pointer;
}
