#include <iostream>
#include <thread>
#include <mutex>
#include <future>
std::mutex mu;
static int counter = 0;
void StartThruster()
{
	try
	{
		/*std::lock_guard<std::mutex> lock(mu);*/
		std::cout << "Launching rocket" << std::endl;
	}
	catch (...)
	{
		
	}
}
void LaunchRocket()
{
	std::lock_guard<std::mutex> lock(mu);
	counter++;
	StartThruster();
}
int main()
{
	//std::thread t1;
	//t1 = std::thread(LaunchRocket);
	//t1.join();
	std::async(&LaunchRocket);
	return 0;
}