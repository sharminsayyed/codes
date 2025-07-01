/*
Write a C++ program to create a class Worker that has data members as Worker_Name, 
No_of_Days_worked, Pay Rate. Create and initialize the object using default constructor, 
parameterized constructor and copy constructor. Also write necessary member function to calculate 
and display the salary of worker.
*/

#include<iostream>

using namespace std;

class Worker
{
    public:
        string wname;
        int nod, pr;
        Worker(){
            wname = "rahil";
            nod = 40;
            pr = 100;
        }

        Worker(string woname , int nofday, int payr)
        {
            wname = woname;
            nod = nofday;
            pr = payr;
        }

        Worker (Worker &w1)
        {
            wname = w1.wname ;
            nod =  w1.nod ;
            pr =  w1.pr  ;
        }

        void display()
        {
            int wsal = nod * pr;
            cout << "\n the salary of worker :" << wsal;
            cout << endl;
        }
};
int main()
{
    int nofday, payr;
    string wname;
    cout << "enter the worker name , no of days , pay rate :";
    cin >> wname >> nofday >> payr;

    cout << "\n default :\n";
    Worker w1;
    w1.display();

    cout << "\n parameter :\n";
    Worker w2(wname, nofday, payr);
    w2.display();

    cout << "\n copy :\n";
    Worker w3(w2);
    w3.display();

    return 0;
}