/*
Write a program for combining two strings also show the execution of dynamic constructor.For this 
declare a class string with data members as name and length.
*/

#include<iostream>

using namespace std;

class stringg{
    public:
        string *s1, *s2;
        stringg(string a, string b)
        {
            s1 = new string(a);
            s2 = new string(b);
            cout << "\n concatenation:" << *s1 <<" "<< *s2;
        }

        ~stringg()
        {
            delete (s1);
            delete (s2);
            cout << "\n deleted ";
        }
};
int main()
{
    string a, b;
    cout << "\n enter string 1:";
    cin >> a;
    cout << "\n enter string 2:";
    cin >> b;
    stringg s(a, b);
    return 0;
}