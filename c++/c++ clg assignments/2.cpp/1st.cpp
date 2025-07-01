// assignment 2 - classes and objects
/*
Write the definition for a class called Cylinder that contains data member’s radius and height. The class has 
the following member functions:
a. void setradius(float) to set the radius of data member
b. void setheight(float) to set the height of data member
c. float volume( ) to calculate and return the volume of thecylinder
d. float area( ) to calculate and return the area of the cylinder.
Write a C++ program to create two cylinder objects and display each cylinder and its area and volume
*/
#include<iostream>
#define PI 3.14
using namespace std;

class cylinder
{
    public:
        float rad, ht;
        void setradius(float r);
        void setheight(float h);
        float volume();
        float area();
};

void cylinder :: setradius(float r)
{
    rad = r;
}

void cylinder ::setheight(float h)
{
    ht = h;
}

float cylinder ::volume()
{
    float v = PI * rad * rad * ht;
    return v;
}

float cylinder :: area()
{
    float a = 2*PI*rad*ht+2*PI*rad*rad;
    return a;
}
int main()
{
    float r, h;
    cout << "enter the radius and height of cylinder :";
    cin >> r >> h;
    cylinder c1;
    c1.setradius(r);
    c1.setheight(h);
    cout << "\n the volume of cylinder :" << c1.volume();
    cout << "\n the area of cylinder :" << c1.area();

    return 0;
}