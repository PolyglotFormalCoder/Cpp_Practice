// Type your code here, or load an example.
// Type your code here, or load an example.
#include<iostream>
#include<memory>
class A
{
public:
    A()
    {
        std::cout << "A 1.Constructor" << std::endl;
    }
    ~A() // Specify as virtual while using smart pointers or new 
    {
       std::cout << "A 6. Destructor" << std::endl;
    }
public:
   
    A(const A& a)
    {
       std::cout << "A 2.1.Copy Constructor" << std::endl;       
    } 
    A(A&& a)
    {
      std::cout << "A 2.2.Move Constructor" << std::endl;
    }
    A& operator=(const A& a)
    {
        std::cout << "A 3.1.Copy assignment" << std::endl;
        return *this;
    }
    A& operator=( A&& a)
    {
        std::cout << "A 3.2.Move assignment" << std::endl;
                
        return *this;
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B 1.Constructor" << std::endl;
    }
    ~B()
    {
       std::cout << "B 6. Destructor" << std::endl;
    }
   
    B(const B& a)
    {
       std::cout << "B 2.1.Copy Constructor" << std::endl;       
    } 
    B(B&& a)
    {
      std::cout << "B 2.2.Move Constructor" << std::endl;
    }
    B& operator=(const B& a)
    {
        std::cout << "B 3.1.Copy assignment" << std::endl;
        return *this;
    }
    B& operator=( B&& a)
    {
        std::cout << "B 3.2.Move assignment" << std::endl;
        return *this;
    }
};

void func1()
{
    A a;
    //A x = a; // Copy constructor is called
    //a = x;   // Copy assignment is called
}
void func2()
{
    A a = A(); // A constructor is called
    //A&& y = std::move(a); // converts lvalue to rvalue
    // or
    //A& z = a; // reference to lvalue
    //A* ap = &a;
    //std::cout << "Pointer holding addrress: "<< ap << " address of rvalue reference: "<<&y << std::endl;
}

void func3()
{
    B b ;
    //B x = b; // Copy constructor of B is called
    //A y = b; // Copy constructor of A is called
}

void func4()
{
    A x = B(); // When move and copy constructor are explicitly defined, then move constructor is called. Is it compiler optimization?
    
   //A y = x;
   //A& yref = x;
}

void func5()
{
    A&& x = B();  // Object B is binded with rvalue reference x to A.                   //  Is it possible to do polyphormic task with rvalue reference?
   //A y = x;
   //A& yref = x;
}
void func6()
{
    A a;
    a = B(); // A is again constructed. When there are move and copy assignment operators explicitly specified, move assignment gets the precedence.
}

void func7()
{
    B b;
    A* a = &b; // can this be polymorphic?
    A& x = b; // There is no copy assignment or move assignment. This is a reference.
}

void func8()
{
    A* a = new B(); // can this be polymorphic?    
    delete a; // Set the base class destructor to be virtual so that the destructor of derived class is called. Look at VTable concept.
}
void func9()
{
    std::unique_ptr<A> a = std::make_unique<B>(); // can this be polymorphic?
    // Set the base class destructor to be virtual so that the destructor of derived class is called. Look at VTable concept.
}


void func10()
{
    A x = B(); // When move and copy constructor are explicitly defined, then move constructor is called. Is it compiler optimization?
    
   A y = x;
   B z;
   y = z;
   
}

void func11()
{
    A&& x = B();  // Object B is binded with rvalue reference x to A.                   //  Is it possible to do polyphormic task with rvalue reference?
    A y = x; // Copy constructor is called. we can use reference here
   //A& yref = x;
}
void func12()
{
    A a = A(); // A constructor is called
    A&& y = std::move(a); // converts lvalue to rvalue
    // or
    A& z = a; // reference to lvalue
    A* ap = &a;
    std::cout << "Pointer holding addrress: "<< ap << " address of rvalue reference: "<<&y << "Address of z :" << &z << std::endl;
}

void func13()
{
    B b;
    B x = b; // Copy constructor of B is called
    A y = b; // Copy constructor of A is called.
}





int main()
{
    std::cout << "----------func1------------" << std::endl;
    func1();
        std::cout << "----------func2------------" << std::endl;
    func2();
    std::cout << "----------func3 Derived Class object ------------" << std::endl;
    func3();
    std::cout << "----------func4 Base class type, Derived class object------------" << std::endl;
    func4();
    std::cout << "----------func5 (same as func3?)------------" << std::endl;
    func5();
    std::cout << "----------func6 (func4 relevance)------------" << std::endl;
    func6();
    std::cout << "----------func7 (same as func5?)------------" << std::endl;
    func7();
    std::cout << "----------func8 ()------------" << std::endl;
    func8();
    std::cout << "----------func9 ()------------" << std::endl;
    func9();
    std::cout << "----------func10 ()------------" << std::endl;
    func10();
    std::cout << "----------func11 ()------------" << std::endl;
    func11();
    std::cout << "----------func12 ()------------" << std::endl;
    func12();
    std::cout << "----------func13 ()------------" << std::endl;
    func13();

}