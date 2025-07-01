/*
Write a C++ program to interchange values of two integer numbers (use call by reference).
*/

#include<iostream>

using namespace std;

void swap(int &a ,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "\n in function a= " << a << " b= " << b;
}
int main()
{
    int m = 10;
    int n = 15;
    cout << "\nbefore function call m =" << m << " n = " << n;
    swap(m, n);
    cout << "\nafter function call m =" << m << " n = " << n;

    return 0;
}