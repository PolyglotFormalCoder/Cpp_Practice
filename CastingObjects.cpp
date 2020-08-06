//example
//conversion from user defined to user defined
//conversion routine in source class
#include<iostream>
#include<cmath>
using namespace std;
class Polar
{
private:
    float radius, angle;    
public:    
    Polar()
    {
        radius=0;
        angle =0;
    }
    Polar(float rad, float ang)
    {
        radius =rad;
        angle=ang;
    }
    //Another way to cast
/*
    operator Cartesian()
    {
        float x=static_cast<int>(radius * cos(angle));
        float y=static_cast<int>(radius * sin(angle));
        cout<<"Polar casting operator is invoked"<<endl;
        return Cartesian(x,y);
    }
    */
    void display()
    {
        cout<<"("<<radius<<","<<angle<<")";
    }
    float getRadius()
    {
        return radius;
    }
     float getAngle()
    {
        return angle;
    }
};
class Cartesian
{
private:
    float xco, yco;
public:
    Cartesian()
    {
        xco=0;
        yco=0;
    }
    Cartesian(float x, float y)
    {
        xco=x;
        yco=y;        
    }
    Cartesian(Polar p)
    {
       xco=static_cast<int>(p.getRadius() * cos(p.getAngle()));
       yco=static_cast<int>(p.getRadius() * sin(p.getAngle()));
       cout<<"Cartesian casting constructor is invoked"<<endl;
    }
    void display()
    {
        cout<<"("<<xco<<","<<yco<<")";
    }
};

int main()
{
    Polar pol(10.0, 0.78);
    Cartesian cart;
    cart=pol;
    cout<<"\nGiven Polar: ";
    pol.display();
    cout<<"\nEquivalent cartesian: ";
    cart.display();
    return 0;
}
