/*
1.Write a C++ program to calculate following series:
(1) + (1+2) + (1+2+3) + (1+2+3+4) + ... +(1+2+3+4+...+n)
*/

#include<iostream>

using namespace std;

int main()
{
    int n, i, j, sum = 0;
    cout << "\nenter the no of terms :";
    cin >> n;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <=i; j++)
        {
            sum = sum + j;
        }
        
    }

    cout << "the addition of series :" << sum;

    return 0;
}