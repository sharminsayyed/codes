/*
Write a C++ program to read two float numbers. Perform arithmetic binary operations +,-,*,/ on
these numbers using inline function. Display the resultant value*/

#include<iostream>
#include<iomanip>

using namespace std;
inline float add(float a , float b)
{
    return (a + b);
}

inline float sub(float a , float b)
{
    return (a - b);
}

inline float mul(float a , float b)
{
    return (a * b);
}

inline float divi(float a , float b)
{
    return (a / b);
}

int main()
{
    float m, n;
    cout << "\n enter 2 integer numbers :";
    cin >> m >> n;
    cout << "\n addition of 2 number :" << add(m, n);
    cout << "\n subtraction of 2 number :" << sub(m, n);
    cout << "\n multiplication of 2 number :" << mul(m, n);
    cout <<setprecision(3)<< "\n division of 2 number :" << divi(m, n);

    return 0;
}