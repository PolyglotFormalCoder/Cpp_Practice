#include <iostream> 
#include <vector>

using namespace std; 


template<typename T>
class Disk_ptr {
string identifier;
T* in_core_address;
// ...
public:
Disk_ptr(const string& s) : identifier{s}, in_core_address{nullptr} { }
T* operator->()
{
if (in_core_address == nullptr)
    in_core_address = new T;
return in_core_address;
}
};

struct Rec {
    string name;
// ...
};
void update(const string& s)
{
Disk_ptr<Rec> p {s}; // get Disk_ptr for s
p->name = "Roscoe"; // update s; if necessary, first retrieve from disk
// ...
}

int main()
{
    update("hello");
}