/*
.Write a C++ program to check if number is prime or not.
*/
#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "enter the number :";
    cin >> n;
    int isprime = 1;
    if(n ==0 && n==1)
    {
        isprime = 0;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if(n% i==0){
            isprime = 0;
            break;
        }

    }
    if(isprime == 1)
        cout <<endl << n << " is a prime number";
    else
        cout <<endl<< n << " is not a prime number";

    return 0;
}