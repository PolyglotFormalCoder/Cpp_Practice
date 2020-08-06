#include<iostream>
#include<string>

int main()
{
   int arr[] = {10,11,21,31,42,51};
   for (int i=0; i < 6; i++)
        std::cout<<arr[i]<<std::endl;
   for (int i=0; i < sizeof(arr)/sizeof(arr[0]); i++)
        std::cout<<arr[i]<<std::endl;
   std::cout<<"sizeof(arr)"<<sizeof(arr)<<std::endl;
   std::cout<<"sizeof(arr[0])"<<sizeof(arr[0])<<std::endl;
   for (int i : arr)
        std::cout<<i<<std::endl;
    for (auto& x : arr)
        std::cout<< x << std::endl;
    for (auto x : {10,11,21,31,42,51})
          std::cout<< x << std::endl;     
}