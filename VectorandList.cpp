#include <iostream>
#include <vector>
#include <chrono>
#include<list>
template<class T>
void list_operations_Template(T list_int_data)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	//set data
	for (int index = 0; index < 100; index++)
		list_int_data.push_back(index + 100);


	//delete data
	for (auto it = list_int_data.begin(); it != list_int_data.end(); )
	{
		if (*it > 110)
		{
			it = list_int_data.erase(it);
		}
		else
		{
			++it;
		}
	}

	//print data	
	for (auto it = list_int_data.begin(); it != list_int_data.end(); ++it)
		std::cout << *it << " ";

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	std::cout << "\nduration for template" << duration << std::endl;
}

void vector_operations(std::vector<int> vector_int_data);
void list_operations(std::list<int> list_int_data);


int main()
{
	
	std::vector<int> vector_int_data1;
	list_operations_Template<std::vector<int>>(vector_int_data1);
	
	std::vector<int> vector_int_data;
	vector_operations(vector_int_data);
	std::cout << "Template vector"  << std::endl;

	std::list<int> list_int_data;
	list_operations(list_int_data);
	std::list<int> list_int_data1;
	list_operations_Template<std::list<int>>(list_int_data1);
	std::cout << "Template list"  << std::endl;

	return 0;
}

void vector_operations(std::vector<int> vector_int_data)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	//set data
	for (int index = 0; index < 100; index++)
		vector_int_data.push_back(index + 100);

	//delete data
	for (auto it = vector_int_data.begin(); it != vector_int_data.end(); )
	{
		if (*it > 110)
		{
			it = vector_int_data.erase(it);
		}
		else
		{
			++it;
		}
	}

	//print data	
	for (auto it = vector_int_data.begin(); it != vector_int_data.end(); ++it)
		std::cout << *it <<" ";

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	std::cout << "\nduration for vector" << duration << std::endl;
}

void list_operations(std::list<int> list_int_data)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();		
	//set data
	for (int index = 0; index < 100; index++)
		list_int_data.push_back(index + 100);

	
	//delete data
	for (auto it = list_int_data.begin(); it != list_int_data.end(); )
	{
		if (*it > 110)
		{
			it=list_int_data.erase(it);
		}
		else
		{
			++it;
		}
	}

	//print data	
	for (auto it = list_int_data.begin(); it != list_int_data.end();++it )
		std::cout << *it << " ";

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	std::cout << "\nduration for list" << duration << std::endl;
}


