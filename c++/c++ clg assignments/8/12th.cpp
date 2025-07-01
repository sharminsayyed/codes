/*
Write a C++ program to create a class Shape with functions to find area of the shape and display
the name of the shape and other essential components of the class. Create derived classes circle,
rectangle and trapezoid each having overridden function area and display. Write a suitable
program to illustrate Virtual Function.
*/
/*overriding :*/
#include<iostream>

using namespace std;

class shape {
    public:
        void virtual area(){};
        void virtual display(){};
};
class circle :public shape{
    public:
        int r;
        float a;
        void area()
        {
            cout << "\n enter radus of circle:";
            cin >> r;
            a = 3.142 * r * r;
        }
        void display()
        {
            cout << "\n shape is cricle "
                 << "\n radius of circle :" << r << "\n area of circle:" << a << endl;
        }
};
class rectangle :public shape{
    public :
        int l, b;
        float a;
        void area()
        {
            cout << "\n enter the lenght and breadth :";
            cin >> l >> b;
            a = l * b;
        }
        void display()
        {
            cout << "\n shape is recatngle \n length and breath is :" << l << b << "\n area of rectangle is :" << a << endl;
        }
};
class trapezoid :public shape{
    public:
        float b1, b2, h, a;
        void area()
        {
            cout << "\n enter base1 base2 height of trapezoid :";
            cin >> b1 >> b2 >> h;
            a = ((b1 + b2) * h) / 2;
        }
        void display()
        {
            cout << "\n shape is trapezoid \n base1 :" << b1 << "\n base2 :" << b2 << "\n height:" << h << "\n area of trapeziod :" << a << endl;
        }
};
int main()
{
    circle c;
    rectangle r;
    trapezoid t;
    cout << "\n details of circle :\n";
    c.area();
    c.display();
    cout << "\n details of rectanngle :\n";
    r.area();
    r.display();
    cout << "\n details of trapezoid :\n";
    t.area();
    t.display();

    return 0;
}