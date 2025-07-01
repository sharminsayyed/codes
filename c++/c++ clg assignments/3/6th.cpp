/*
Write C++ program to create a class Employee containing data members Emp_no, Emp_Name,
Designation and Salary. Create and initialize the objects using default, parameterized and Copy
Constructor. Also write member function to calculate Income tax of the employee which is 20%
of salary*/

#include<iostream>

using namespace std;

class Employee
{
    public:
        int eno;
        string ename, edesg;
        int esal;

        Employee()
        {
            eno = 12;
            ename = "sharmin";
            edesg = "ceo";
            esal = 23000;
        }

        Employee(int empno , string empname , string empdesg , int empsal)
        {
            eno = empno;
            ename = empname;
            edesg = empdesg;
            esal = empsal;
        }

        Employee(Employee &e1)
        {
            eno = e1.eno;
            ename = e1.ename;
            edesg = e1.edesg;
            esal = e1.esal;
        }

        void display()
        {
            cout << "\n employee no :" << eno;
            cout << "\n employee name :" << ename;
            cout << "\n employee designation :" << edesg;
            cout << "\n employee salary :" << esal;
            cout << "\n income tax :" << 0.20 * esal;
            cout << endl;
        }
};
int main()
{
    int empno, empsal;
    string empname, empdesg;
    cout << "\n enter emp  number :";
    cin >> empno;
    cout << "\n enter emp  name :";
    cin >> empname;
    cout << "\n enter emp  designation :";
    cin >> empdesg;
    cout << "\n enter emp  salary :";
    cin >> empsal;

    cout << "\n default constructor : \n";
    Employee e1;
    e1.display();

    cout << "\n parameter constructor :\n";
    Employee e2(empno, empname, empdesg, empsal);
    e2.display();

    cout << "\n copy constructor :\n";
    Employee e3(e2);
    e3.display();

    return 0;
}