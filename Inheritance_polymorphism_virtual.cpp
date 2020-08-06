#include<iostream>
#include<memory>
#include<vector>

/* Keywords: 
Inheritance, 
runtime-polymorphism, 
Function overriding
base class pointer to derived class, 
Abstract class, 
virtual functions,
virtual destructors
Constructors
Move constructor
Move assignment operator
Copy constructor
Copy assignment operator
public methods/functions, protected and private data members
assigning derived object d2 to derived object d1 through reference

Summary:
In this implementation we demonstrate, object creation through pointer/reference, object destruction (virtual destructor),
 method calls in the context of Inheritance and runtime-polymorphism. 

Polymorphism: Different forms. 
Runtime-polymorphism (or dynamic method dispatch, late dynamic binding): In this approach, a method to be called/executed
is determined during the run-time. This is also called as late binding. The advantage of this approach is that

1. There is a single variable of base class type pointing to or references to derives class. Only one variable to keep track
of while programming
2. The methods in both base class and derived classes can have same names. This enables ease of programming
3. When we have array of objects pointed by base class variable, we can easily create a loop with single base class calling
the method name common to all base and derived classes. During the run-time, object in scope is determined and correct
method is executed. 

The disadvantage of this approach is 
1. Performance - Late binding causes delay in execution
2. Readibility - A programmer needs to visualize runtime execution to determine how the implemented code works

Ingredients (static): We need - a base class, derived class(es), virtual specifier for methods/functions, override specifier (C++11), 
Recipe(dynamic): Implement a base class and two classes that derive from the base class. 
*/

class Vehicle
{
public:
    Vehicle(){std::cout << "Vehicle Constructor" << std::endl;}

    virtual ~Vehicle(){std::cout << "Vehicle Destructor" << std::endl;}

    virtual void getData() 
    {
        std::cout << "Vehicle basedata :"<< basedata << " Vehicle data :"<< data <<std::endl;
    }

    Vehicle(const Vehicle& other)
    {
        std::cout << "Vehicle copy constructor" << std::endl;
        this->basedata = other.basedata;
        this->data = other.data;
    }

    Vehicle(Vehicle&& other)
    {
        std::cout << "Vehicle move constructor" << std::endl;
        this->basedata = other.basedata;
        this->data - other.data;
    }
    Vehicle& operator=(const Vehicle& other)
    {
        std::cout << "Vehicle copy assignment" << std::endl;
        this->basedata = other.basedata;
        this->data = other.data;
        return *this;
    }


protected:
    int basedata = -1;
    int data = -2;
};

class Car : public Vehicle
{
public:
     Car(){
         basedata = 3;
         std::cout << "Car Constructor" << std::endl;
     }
     ~Car() {std::cout << "Car destructor" << std::endl;}
    void getData() //override
    {
        std::cout << "Car basedata :" << basedata << " Car data :" << cardata <<std::endl;
    }
    Car& operator=(const Car& other)
    {
        this->cardata = other.cardata;
        this->basedata = other.basedata;
        this->data = other.data;
        return *this;
    }
    void setBasedata()
    {
        basedata = 100;
    }
    void setData()
    {
        cardata = 10;
    }
private:
    int cardata = 1;

};

class MotorBike : public Vehicle
{
public:
     MotorBike(){
         basedata = 5;
         std::cout << "MotorBike Constructor" << std::endl;
     }
      ~MotorBike() {std::cout << "Motorbike destructor" << std::endl;}
    void getData() //override
    {
        std::cout << "MotorBike basedata :"<< basedata << " MotorBike data :"<< bikedata << std::endl;
    }
    MotorBike& operator=(const MotorBike& other)
    {
        this->bikedata = other.bikedata;
        this->basedata = other.basedata;
        this->data = other.data;
        return *this;
    }
    void setBasedata()
    {
        basedata = 50;
    }
    void setData()
    {
        bikedata = 10;
    }

private:
    int bikedata = 2;
};

void func(Vehicle& vehicle)
{
    vehicle.getData();
}

void funcRvalueReference(Vehicle&& vehicle)
{
    vehicle.getData();
}

void func1()
{
    Car ca;
    MotorBike mb;

    Vehicle* vh[] = { &ca, &mb };

    for (int i = 0; i < 2; i++)
    {
        vh[i]->getData();
    }
}

void func2()
{
    Car ca;
    MotorBike mb;
    Vehicle& vhref = ca;
    std::cout << "Car:Initial :" ;
    vhref.getData();
    vhref = mb; // (Implicit) copy assignment is called
    std::cout << "Car:New:" ;
    vhref.getData(); 
   std::cout << "--------------------------------" << std::endl;
    std::vector<Vehicle> vh = {};
    vh.emplace_back(Car());
    vh.emplace_back(MotorBike());
    for (Vehicle& x : vh)
    {
        x.getData();
    }
    std::cout << "-------------------------------" << std::endl;
    Car c1;
    Car& c1ref = c1;
    c1ref.getData();
    Car c2;
    c2.setBasedata();
    c2.setData();
    c1ref = c2;
    c1ref.getData();
    std::cout << "-------------------------------" << std::endl;
    
    Car car;
    MotorBike motorbike;
    func(car);
    func(motorbike);    
}

void func3()
{
    Vehicle&& vhref = Car();
    std::cout << "Car:Initial :";
    vhref.getData();
    vhref = MotorBike();
    std::cout << "Car:New:";
    vhref.getData();

   std::cout << "--------------------------------" << std::endl;

    std::vector<Vehicle>&& vh = {Car(), MotorBike()};

    for (Vehicle& x : vh)
    {
        x.getData();
    }
   std::cout << "--------------------------------" << std::endl;
   
   funcRvalueReference(Car());
   funcRvalueReference(MotorBike());
}

void func4()
{
    Vehicle* ca = new Car();
    //MotorBike* mb = new MotorBike();
    delete ca;
    //delete mb;
}


int main()
{
    std::cout << "****************FUNC1*****************" << std::endl;
    func1();
    std::cout << "****************FUNC2*****************" << std::endl;
    func2();
std::cout << "****************FUNC3*****************" << std::endl;
    func3();
std::cout << "****************FUNC4*****************" << std::endl;
    func4();
}