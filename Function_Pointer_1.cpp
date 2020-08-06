// Function_Pointer_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void Function1(int number1)
{
	std::cout << "number1 is " << number1;
}
int main()
{
	void (*Function1_ptr)(int);
	Function1_ptr = Function1;
	(*Function1_ptr)(10);
}

