/*
Write a C++ program using class to calculate simple interest amount. (Use parameterized constructor 
with default value for rate) formula= si=pricipal amt*rate*no of years
*/
#include<iostream>

using namespace std;

class si{
    public:
    si(int p ,int n,int r =30)
    {
        int si;
        si = p * n * r;
        cout << "\n simple interest is :" << si;
    }
};
int main()
{
    int pamt, noy, rate;
    cout << "\n enter the principal amount :";
    cin >> pamt;
    cout << "\n enter the no of years :";
    cin >> noy;
    cout << "\nenter the rate :";
    cin >> rate;
    // default rate value is set
    si s1(pamt, noy);

    // if rate is not set
    si s2(pamt, noy, rate);

    return 0;
}