#include <iostream> 
#include <vector>
using namespace std; 

struct Representation
{
int x;
};


class Image {
public:
    // ...
    Image(const Image& a); // copy constr uctor
    Image(Representation* r, bool s);
    // ...
    void write_block();
    void display();
    
    // ...
private:
    void clone(); // copy *rep
    Representation* rep;
    bool shared;
};

void Image::display()
{
    std::cout<<"value of rep: "<<rep<<" value of *rep: "<<rep->x<<std::endl;
}

Image::Image(Representation* r, bool s):rep{r}, shared{s}
{
    std::cout<<"constructed"<<std::endl;
}

Image::Image(const Image& a) // do shallow copy and prepare for copy-on-wr ite
            :rep{a.rep},
            shared{true}
{
    std::cout<<"copy constructed"<<std::endl;
}

void Image::write_block()
{
if (shared) {
clone(); // make a copy of *rep
rep->x = rep->x+1000;
shared = false; // no more sharing
}
// ... now we can safely write to our own copy of rep ...
}

void Image::clone()
{
    int temp = rep->x;
    rep = new Representation{temp};    
}

int main() 
{ 
    Image image1{new Representation{100}, false};
    Image image2{new Representation{200}, false};
    Image image3 = image1;    
    image1.display();
    image3.display();
    image3.write_block();
    image1.display();
    image3.display();
	return 0; 
} 
