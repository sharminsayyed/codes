/*
Write a C++ program to display factors of a number.
*/

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "\n enter a positive  numberr :";
    cin >> n;
    cout << "the factors of " << n << ":";
    for (int i = 1; i <= n; i++)
    {
        if(n % i == 0){
            cout << i << "\t";
        }
    }
    
    return 0;
}