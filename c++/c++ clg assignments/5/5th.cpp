/*
.Write a C++ program to check minimum and maximum of two integer number (use inline
function and conditional operator)
*/

#include<iostream>

using namespace std;
inline int max (int a ,int b)
{
    return (a > b ? a : b);
}

inline int min(int a , int b)
{
    return (a < b ? a : b);
}
int main()
{
    int m, n;
    cout << "\n enter the 2 integer :";
    cin >> m >> n;
    cout << "\n maximum of 2 numbers :" << max(m, n);
    cout << "\n minimum of 2 number :" << min(m, n);
    return 0;
}