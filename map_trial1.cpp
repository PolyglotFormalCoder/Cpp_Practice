// map_trial1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>
#include <unordered_map>
int main()
{
    std::cout << "map!\n";
	std::map<int, int> map1;
	map1 = { std::pair<int,int> (1,2),
			 std::pair<int,int> (3,4) };
	map1.insert(std::pair<int, int>(5, 6));
	map1.erase(5);
	for (auto itr = map1.begin(); itr != map1.end(); itr++)
	{
		std::cout << "map pair" << itr->first << itr->second << std::endl;
	}
	std::cout << "unordered map!\n";
	std::unordered_map<int, int> map2;
	map2 = { std::pair<int,int>(1,2),
			 std::pair<int,int>(3,4) };
	map2.insert(std::pair<int, int>(5, 6));
	map2.erase(5);
	for (auto itr = map2.begin(); itr != map2.end(); itr++)
	{
		std::cout << "unordered map pair" << itr->first << itr->second << std::endl;
	}
	std::cout << "unordered multi map!\n";
	std::unordered_multimap<int, int> map3;
	map3 = { std::pair<int,int>(1,2),
			 std::pair<int,int>(3,4) };
	map3.insert(std::pair<int, int>(5, 6));
	map3.erase(5);
	for (auto itr = map3.begin(); itr != map3.end(); itr++)
	{
		std::cout << "unordered map pair" << itr->first << itr->second << std::endl;
	}
}

