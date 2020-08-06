
#include<iostream>

class A
{
public:
    A() 
    {
        std::cout << "A constructor" << std::endl;
    }
    ~A()
    {
         std::cout << "A destructor" << std::endl;       
    }
    A(A const& other)
    {
        std::cout << "A copy constructor" << std::endl;
    }
    A(A&& other)
    {
        std::cout << "A move constructor" << std::endl;
    }
    A& operator=(const A& other)
    {
        std::cout << "A copy asignment operator" << std::endl;
        return *this;
    }
    A& operator=(A&& other)
    {
        std::cout << "A move asignment operator" << std::endl;
        return *this;
    }

    void setData(int x)
    {
        data = x;
    }
    int getData()
    {
        return data;
    }
private:
    int data;

};

class B : public A
{
public:
    B() 
    {
        std::cout << "B constructor" << std::endl;
    }
    ~B()
    {
         std::cout << "B destructor" << std::endl;       
    }
    B(B const& other)
    {
        std::cout << "B copy constructor" << std::endl;
    }
    B(B&& other)
    {
        std::cout << "B move constructor" << std::endl;
    }
    B& operator=(const B& other)
    {
        std::cout << "B copy asignment operator" << std::endl;
        return *this;
    }
    B& operator=(B&& other)
    {
        std::cout << "B move asignment operator" << std::endl;
        return *this;
    }
};

void func(A& a)
{
    a.setData(33);
}
void funcp(A* a)
{
    a->setData(44);
}
A* funcObj(A&& a)
{
    a.setData(55);
    return &a;
}
A& funcObj1(A&& a)
{
    a.setData(77);
    return a;
}
A funcObj2(A&& a)
{
    a.setData(88);
    return a;
} // a goes out of scope

void func1()
{
  std::cout << "----------A a =  B()------------" << std::endl;  
  A a =  B(); // If there is a move and copy constructor, move constructor gets precendence and is called. Disable move constructor to use copy constructor. Move constructor generally does shallow copy.
  //A c = std::move(a); // move does not actually move. it casts from lvalue to rvalue.

}// Destructor is called here

void func2()
{
  std::cout << "----------A&& a =  B()------------" << std::endl;
  A&& a =  B(); // The base class destructor need not be virtual

}// Destructor is called here

void func3()
{
  std::cout << "----------A* a = new B()------------" << std::endl;
  A* a =  new B();
  //A c = std::move(*a);
  delete a; 
}// Destructor is called here

void func4()
{
  std::cout << "----------A* a = &B()------------Not Possible B() is an rvalue" << std::endl;
  //A* a =  &B(); // B() is an rvalue. Cannot take the address. 
} // Destructor is called here

void func5()
{
  std::cout << "----------A&& a =  B() operations------------" << std::endl;
  A&& a =  B(); // The base class destructor need not be virtual
  //A c = std::move(a);
  a.setData(22);
  std::cout<< "Returning data :" << a.getData() << std::endl;
  A& b = a;// rvalue is a lvalue
  std::cout<< "Returning data :" << b.getData() << std::endl;
  A* c = &a; 
  std::cout<< "Returning data :" << c->getData() << std::endl;
  //A& d = B(); not allowed. B() is a rvalue. Cannot have reference to rvalue. same as int x = &5; This is not applicable.
  A e = a; // copy constructor is called
  func(a);
  std::cout<< "Returning data :" << a.getData() << std::endl;
  funcp(&a);
  std::cout<< "Returning data :" << a.getData() << std::endl;
  auto* x = funcObj(B()); // B() is an rvalue here. 
  std::cout<< "Returning data :" << x->getData() << std::endl;
  auto& y = funcObj1(B());
  std::cout<< "Returning data :" << y.getData() << std::endl;
  auto z = funcObj2(B());
  std::cout<< "Returning data :" << z.getData() << std::endl; // garbage value

}// Destructor is called here
int main()
{
  
  func1();  // concrete class
  func2();  // concrete class with rvalue reference
  func3(); // declare base class A destructor as virtual to make this function produce correct results. 
  func4();
  func5();
}