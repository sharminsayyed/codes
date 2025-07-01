/*
Create a class named „DISTANCE‟ with: - feet and inches as data members. The class has the following 
member functions:
a. To input distance
b. To output distance
c. To add two distanceobjects
Write a C++ program to create objects of DISTANCE class. Input two distances and output the sum.
*/
#include<iostream>
using namespace std;

class Distance{
    public:
        int f, i;
        void input();
        void output();
        int add(int, int, int, int);
};

void Distance::input()
{
    cout <<endl<< "enter the feet andinches for distance:";
    cin >> f >> i;
}

void Distance::output()
{
    cout <<endl<< "feet : " << f;
    cout <<endl<< "inches:" << i;
}

int Distance :: add(int f1 , int i1 , int f2, int i2)
{
    int tfeet, tinches, tdistance;
    tfeet = f1 + f2;
    tinches = i1 + i2;
    if(tinches >= 12)
    {
        tfeet++;
        tinches = tinches - 12;
    }
    tdistance = tfeet + tinches;
    cout << "totaldistance : " << tdistance;
    return tdistance;
}

int main()
{
    Distance d1 ,d2,d3;
    d1.input();
    d1.output();
    d2.input();
    d2.output();
     int totaldistance = d1.add(d1.f, d1.i, d2.f, d2.i);
    // cout << endl<< "total distance : " << totaldistance;

    return 0;
}