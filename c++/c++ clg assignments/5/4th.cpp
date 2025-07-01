/*
1.Write a C++ program to accept length and width of a rectangle. Calculate and display perimeter
as well as area of a rectangle by using inline function.
*/

#include<iostream>

using namespace std;
inline int area(int l , int w)
{
    return (l * w);
}

inline int perimeter(int l , int w)
{
    return (2*(l + w));
}
int main()
{
    int length, width;
    cout << "\n enter the lenght and width of rectangle :";
    cin >> length >> width;
    cout << "\n Area of rectangle :" << area(length, width);
    cout << "\n Perimeter of rectangel :" << perimeter(length, width);
    return 0;
}