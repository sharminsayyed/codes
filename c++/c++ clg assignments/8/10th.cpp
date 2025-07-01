/*
Write a C++ program with Student as abstract class and create derive classes Engineering,
Medicine and Science having data member rollno and name from base class Student. Create
objects of the derived classes and access them using array of pointer of base class Student
*/
#include<iostream>

using namespace std;
class student{
    public :
        int rn;
        string nm;
        void virtual get() = 0;
        void virtual put() = 0;
};
class engineering: public student{
    public:
    void get()
    {
        cout << "\nenter the engineering student rollno and name :";
        cin >> rn >> nm;
    }
    void put()
    {
        cout << "\n engineering studnet rollno :" << rn << "\n name :" << nm << endl;
    }
};
class medicine:public student{
    public:
    void get()
    {
        cout << "\nenter the medicine student rollno and name :";
        cin >> rn >> nm;
    }
    void put()
    {
        cout << "\n medicine studnet rollno :" << rn << "\n name :" << nm << endl;
    }
};
class science :public student{
    public:
    void get()
    {
        cout << "\n enter science student rollno, name:";
        cin >> rn >> nm;
    }
    void put()
    {
        cout << "\n science student roll no:" << rn << "\n name :" << nm << endl;
    }
};
int main()
{
    student *s[3];
    engineering e;
    science sc;
    medicine m;
    s[0]=&e;
    s[1] = &sc;
    s[2] = &m;
    cout << "\n enter the details";
    s[0]->get();
    s[1]->get();
    s[2]->get();
    // display
    s[0]->put();
    s[1]->put();
    s[2]->put();

    return 0;
}