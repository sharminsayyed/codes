/*  Implement the following class hierarchy:
Employee: code, ename, desg
Manager (derived from Employee): year_of_experience, salary
Define appropriate functions to accept and display details.
Create n objects of the manager class and display the records.
Write main function that uses the above class and its member functions. 
*/
/* single inheritance */
#include<iostream>

using namespace std;

class Employee
{
    public:
        int ec;
        string enm, edesg;
        void accept()
        {
            cout << "\n enter the employee code ,name , designation :";
            cin >> ec >> enm >> edesg;
        }
        void display()
        {
            cout << "\n employee code:" << ec << "\n name :" << enm << "\n designation :" << edesg;
        }
};

class Manager : public Employee{
    public:
        int exp;
        float sal;
        void accept()
        {
            Employee::accept();
            cout << "\n enter the years of experience , salary :";
            cin >> exp >> sal;
        }
        void display()
        {
            Employee::display();
            cout << "\n experience :" << exp << "\n salary :" << sal;
            cout << endl;
        }
};
int main()
{
    int n, i;
    cout << "\n enter no of emplyee :";
    cin >>n;
    Manager m[n];
    for ( i = 0; i < n; i++)
    {
        m[i].accept();
    }
    for ( i = 0; i < n; i++)
    {
        m[i].display();
    }
    

    return 0;
}