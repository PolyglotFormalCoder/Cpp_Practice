#include <iostream>
#include <vector>
#include <thread>
class Points
{
private:
	std::vector<int> points;
	int length;
public:
	Points(std::vector<int> m_Points, int m_length):points(m_Points), length(m_length)
	{}
	~Points() { length = 0; points.clear(); }
	void print_vector()
	{
		for (int index = 0; index < length; index++)
			std::cout << points[index] << std::endl;
	}
};

int main()
{
    std::cout << "Hello World!\n";
	std::vector<int> points = { 1,2,3,4,5 };
	Points line(points,5);
	Points curve(points, 5);
	
	std::thread t1(&Points::print_vector, line);
	std::thread t2(&Points::print_vector, curve);
	std::cout<< "main thread id:"<< std::this_thread::get_id() << std::endl;
	std::cout << "thread1 id:" << t1.get_id() << std::endl;
	std::cout << "thread2 id:" << t2.get_id() << std::endl;
	t1.join();
	t2.join();
}
