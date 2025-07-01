// constructor parameter , (default),copy
/*
Write a program to find sum of numbers between 1 to n using constructor where value of n will be 
passed to the constructor
*/
#include<iostream>

using namespace std;

class sum{
    public:
        sum(int n)
        {
            int i, sum = 0;
            for (i = 1; i <= n;i++)
            {
                sum = sum + i;
                
            }
            cout << "sum :"<<sum;
        }
};
int main()
{
    int num;
    cout << "\n enter the number :";
    cin >> num;
    sum s1(num);
    return 0;
}