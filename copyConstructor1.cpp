#include <iostream>
#include <vector>
struct Tracer {
std::string mess;
Tracer(const std::string& s) :mess{s} { std::cout << mess; }
~Tracer() {std::cout << "˜" << mess; }
};
void f(const std::vector<int>& v)
{
Tracer tr {"in f()\n"};
for (auto x : v) {
Tracer tr {std::string{"v loop "}+std::to_string(x)+'\n'}; // §25.2.5.1
}
}

int main()
{
    std::vector<int> vector1{2,3,5};
    f(vector1);

    return 0;
}