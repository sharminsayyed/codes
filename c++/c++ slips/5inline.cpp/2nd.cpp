/*
Write a C++ program to implement a class printdata to overload print function as follows:
void print(int) - outputs value followed by the value of the integer.
Eg. print(10) outputs - value 10
void print(char *) – outputs value followed by the string in double quotes.
Eg. print(“hi”) outputs value “hi”
*/
#include<iostream>

using namespace std;

class printdata
{
    public:
    void print(int n)
    {
        cout << "\n value :" << n;
    }
    void print (char *s)
    {
        cout << "\nvalue \"" << s << "\"";
        // \" will give " notation in the output
    }
};
int main()
{
    int n = 10;
    printdata p;
    p.print(n);
    p.print("hello");
    return 0;
}