/*
Write a C++ program to overload function Volume and find Volume of Cube, Cylinder and
Sphere*/

/*
If any class has multiple functions with same names but different parameters then they are said to be 
overloaded. Function overloading allows you to use the same name for different functions, to perform, either 
same or different functions in the same class
*/

#include<iostream>

using namespace std;
class shape{
    public:
        void volume(int n)
        {
            cout << "\n volume of cube :" <<  (n * n * n);
        }

        void volume(float r, float h)
        {
            cout << "\n volume of cylinder: " << (3.14 * r * r * h);
        }

        void volume(float r)
        {
            cout<<"\n volume of sphere:"<<((4*3.14*r*r*r)/3);
        }
};
int main()
{
    int side;
    float hei1, rad1, rad2;
    cout << "\n enter the side of cube :";
    cin >> side;
    shape s1;
    s1.volume(side);

    cout << "\n enter the radius and height of cylinder :";
    cin >> rad1 >> hei1;
    shape s2;
    s2.volume(rad1,hei1);

    cout << "\n enter the radius of sphere :";
    cin >> rad2;
    shape s3;
    s3.volume(rad2);
    return 0;
}