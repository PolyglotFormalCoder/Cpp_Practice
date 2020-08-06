#include <iostream>
#include<vector>
#include<iterator>
int main()
{
	std::vector<int> vector1 = { 1,2,3,4,5 };
	vector1.push_back(22);
	int pop;
	vector1.pop_back();
	vector1.insert(vector1.end(), 400);
	vector1.erase(vector1.end()-1);
	vector1.data();
	std::cout << "vector size" << vector1.size()<<std::endl;
	std::cout << "vector capacity" << vector1.capacity() << std::endl;
	vector1.resize(3);
	vector1.shrink_to_fit();
	std::cout << "vector size" << vector1.size()<<std::endl;
	std::cout << "vector capacity" << vector1.capacity() << std::endl;	
	vector1.push_back(44);
	vector1.push_back(44);
	vector1.push_back(44);
	for (std::vector<int>::iterator iterator_1 = vector1.begin(); iterator_1 != vector1.end(); iterator_1++)
	{
		std::cout << *iterator_1 << std::endl;
	}
	std::cout << "vector size" << vector1.size() << std::endl;
	std::cout << "vector capacity" << vector1.capacity() << std::endl;
}
