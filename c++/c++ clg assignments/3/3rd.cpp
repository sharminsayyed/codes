/*
Write a C++ program to create a class Number which contains two integer data members. Create and 
initialize the object by using default constructor, parameterized constructor. Write a member function 
to display maximum from given two numbers for allobjects.
*/

#include<iostream>

using namespace std;
class Max{
    public:
        int a, b;
        Max()
        {
            a = 60;
            b = 78;
        }
        Max(int x, int y)
        {
            a = x;
            b = y;
        }
        
        void maxx()
        {
            if(a>b)
                cout << endl
                     << a << "  is maximun then " << b;
            else
                cout << endl
                     << b << " is maximum then " << a;
        }
};
int main()
{
    int x, y;
    cout << "\n enter the x and y :";
    cin >> x >> y;
    // default constructor
    Max m1;
    m1.maxx();
    // parametrized constructor
    Max m2(x, y);
    m2.maxx();

    return 0;
}