// inline friend and function overloading 
/*
Write a C++ program to print area of circle, square and rectangle using inline function. */
#include<iostream>

using namespace std;
inline int area_square(int s)
{
    return (s * s);
}

inline int area_rectangle(int l,int w)
{
    return (l * w);
}

inline int area_circle(int r)
{
    return (3.14 * r * r);
}
int main()
{
    int rad, side, len, wid;
    cout << "\n enter the radius:";
    cin >> rad;
    cout << "\n Area of cirlce :" << area_circle(rad);
    cout << "\n enter the side:";
    cin >> side;
    cout << "\n Area of square :" << area_square(side);
    cout << "\n enter the length and width:";
    cin >> len>>wid;
    cout << "\n Area of cirlce :" <<area_rectangle(len ,wid);
    

    return 0;
}