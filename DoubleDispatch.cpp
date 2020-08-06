// CPP program to illustrate 
// Run Time Type Identification 
#include<iostream> 
#include <memory>
using namespace std; 
class Rectangle;
class Ellipse;

class Shape {
public:
  virtual std::string name() const {
    return typeid(*this).name();
  }
  virtual void Intersect(const Ellipse* e) = 0;
  virtual void Intersect(const Rectangle* r2) = 0; 
};

class Ellipse : public Shape {
    virtual void Intersect(const Ellipse* e);
    virtual void Intersect(const Rectangle* r2);
};

class Rectangle : public Shape {
    virtual void Intersect(const Ellipse* e);
    virtual void Intersect(const Rectangle* r2);
};

// Overloaded Intersect methods.
void Ellipse::Intersect(const Ellipse* e) {
  std::cout << "Ellipse x Ellipse [names r=" << this->name()
            << ", e=" << e->name() << "]\n";
}

void Ellipse::Intersect(const Rectangle* r2) {
  std::cout << "Ellipse x Rectangle [names r1=" << this->name()
            << ", r2=" << r2->name() << "]\n";
}

// Overloaded Intersect methods.
void Rectangle::Intersect(const Ellipse* e) {
  std::cout << "Rectangle x Ellipse [names r=" << this->name()
            << ", e=" << e->name() << "]\n";
}

void Rectangle::Intersect(const Rectangle* r2) {
  std::cout << "Rectangle x Rectangle [names r1=" << this->name()
            << ", r2=" << r2->name() << "]\n";
}


int main() 
{ 
	std::unique_ptr<Shape> pr1(new Rectangle);    
    std::unique_ptr<Shape> pe(new Ellipse);

    std::cout << "Dynamic type dispatch\n";
    pr1->Intersect( dynamic_cast<const Ellipse*>(pe.get()));
    pr1->Intersect( dynamic_cast<const Rectangle*>(pr1.get()));
    pe->Intersect(dynamic_cast<const Rectangle*>(pr1.get()));
    pe->Intersect(dynamic_cast<const Ellipse*>(pe.get()));
  

	return 0; 
} 
