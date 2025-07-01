/*
 Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a
C++ program to perform following necessary member functions:
a. To read time
b. To display time in format like: hh:mm:ss
c. To add two different times (Use Objects as argument)
*/
#include<iostream>
using namespace std;

class time
{
    public:
        int h, m, s;
        void accept();
        void display();
        void add(time t1, time t2);
};

void time ::accept()
{
    cout << "\nenter  hours :";
    cin >> h;
    cout << "\nenter minutes  :";
    cin >>m ;
    cout << "\nenter  seconds  :";
    cin >> s;
}
void time ::display()
{
     cout <<endl<<"time:"<<h<<":"<<m<<":"<<s;
     cout << endl;
}

void time ::add(time t1 , time t2)
{
    int th, tm, ts,tt;
    th = t1.h + t2.h;
    tm = t1.m + t2.m;
    ts = t1.s + t2.s;
    
    if(ts >= 60)
    {
        tm++;
        ts -=60;
    }
    if(tm >= 60)
    {
        th++;
        tm -=60;
    }
     cout <<endl<<"total time:"<<th<<":"<<tm<<":"<<ts;
    
}
int main()
{
    time t1, t2;
    t1.accept();
    t1.display();
    t2.accept();
    t2.display();
    t1.add(t1, t2);

    return 0;
}