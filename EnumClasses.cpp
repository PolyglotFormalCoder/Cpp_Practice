//experiment to show enum class is better than enum
//enum classes are strongly scoped and strongly typed (type safe)
#include <iostream>
int main()
{
    //make it enum class then you get an error immediately
enum FRUIT {MANGO, APPLE, BANANA};

enum INDIAN_FRUIT { KIWI};

FRUIT fruit_1;
fruit_1 = FRUIT::MANGO;

if (FRUIT::MANGO == INDIAN_FRUIT::KIWI)
{}

return 0;
}