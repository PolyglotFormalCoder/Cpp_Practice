#include <iostream>
#include <vector>
#include <thread> 
#include <chrono>
#include <future>
void f_add(int&);
void f_mul(int&);
void f_sub(int&);
void f_div(int&);


int main()
{
	std::vector<double> some_vec;
	std::vector<double> vec2;
	std::cout << "The START" << '\n';
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	std::chrono::high_resolution_clock::time_point time1 = std::chrono::high_resolution_clock::now();
	/*std::thread t1{ f_add, std::ref(a)};
	std::thread t2{ f_mul, std::ref(b) };
	std::thread t3{ f_sub, std::ref(c) };
	std::thread t4{ f_div, std::ref(d) };
	t1.detach();
	t2.detach();
	t3.detach();
	t4.detach();*/
	std::async(std::launch::async, &f_add, std::ref(a));
	std::async(std::launch::async, &f_mul, std::ref(b));
	std::async(std::launch::async, &f_sub, std::ref(c));
	std::async(std::launch::async, &f_div, std::ref(d));
	
	/*f_add(a);
	f_mul(b);
	f_sub(c);
	f_div(d);*/
	std::chrono::high_resolution_clock::time_point time2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();

	std::cout << "\nduration for template" << duration << std::endl;
	std::cout << "ADD:" << a << "   MUL:" << b << "  SUB:" << c << "  DIV:" << d<<std::endl;

	std::cout << "The END" << '\n';
}
void f_add(int& a)
{
	a = a + a;
}

void f_mul(int &b)
{
	b= b * b;
}

void f_sub(int& c)
{
	c= c - c;
}

void f_div(int& d)
{
	d= d / d;
	throw std::runtime_error("Catch me in MAIN");

}