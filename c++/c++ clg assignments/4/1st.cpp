// Destructor is a member function which destructs or deletes an object that has been created by constructor.
/*Writea programto create memory space using the new keyword and to destroy it using delete keyword */
#include<iostream>

using namespace std;

class member
{
    public :
        int *p;
        void show(int n)
        {
            p = new int(n);
            cout << "\n number: " << n;
        }
};
int main()
{
    member n1;
    int m;
    cout << "\n enter number :";
    cin >> m;
    cout << "\nu gave";
    n1.show(m);
    delete (n1.p);
    return 0;
}