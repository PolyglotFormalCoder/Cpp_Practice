#include <iostream>
#include <forward_list>
#include <iterator>


void print(std::forward_list<int>& flist1)
{
    std::cout<<"printing: ";
    for (auto x : flist1)
   {
       std::cout<<x<<"  ";
   }
   std::cout<<std::endl;
}

int main()
{
   std::forward_list<int> flist1 ={1,2,3,4,5};
   print(flist1);
   flist1.push_front(100);
   print(flist1);
   flist1.pop_front();
   print(flist1);
   flist1.push_front(0);
   print(flist1);
   flist1.pop_front();
   print(flist1);
   std::cout<<" max size: "<<flist1.max_size()<<std::endl;  
   if(flist1.empty())
   {
       std::cout<<" forward_list is empty";
   }
   std::cout<<flist1.front()<<std::endl;
 
   for (auto it = flist1.begin(); it != flist1.end(); ++it)
   {
       std::cout<<*it<<" ";
   }
   std::cout<<std::endl;  
   auto it_pos = flist1.begin();   
   flist1.insert_after(it_pos,500);
   print(flist1);
   flist1.emplace_front(700);
    print(flist1);
    flist1.emplace_after(flist1.begin(),1700);
    print(flist1);
    std::forward_list<int> flist2 ={10,20,30,40,50};
    flist2.swap(flist1);
    print(flist1);
    print(flist2);
    flist2.clear();
    print(flist2);
    std::forward_list<int, std::allocator<int>>* vec_pointer = new std::forward_list<int>();
    (*vec_pointer).push_front(100);
    delete vec_pointer;
}
