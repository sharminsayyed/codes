/*2.Write a C++ programto create a class Distance which contains data members as kilometer, meter.
Write a program to perform the following functions
a.To accept distance
b.To display distance
c.To overload > operator to compare two distance*/

#include<iostream>

using namespace std;
class Distance{
    public:
        int km, m;
        void accept()
        {
            cout << "\n enter the distance in kilometer and meter :";
            cin >> km >> m;
        }

        void display()
        {
            cout << "\n distance :" << km << " kilometer " << m << " meter";
        }

        int operator >(Distance &d1)
        {
            if(  ( (km > d1.km) ||(km == d1.km) )   && (m > d1.m) )
                return 1;
            else
                return 0;
        }
};
int main()
{
    Distance d1, d2;
    d1.accept();
    d2.accept();
    d1.display();
    d2.display();

    if(d1 > d2)
        cout << "\n distance 1 is greater ";
    else
        cout << "\n distance 2 is greater";

    return 0;
}