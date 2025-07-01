/*
Write a C++ program to create a class employee containing salary as a data member. Write
necessary member functions to overload the operator unary pre and post decrement "--"
for decrementing salary*/

#include<iostream>

using namespace std;
class Employee{
    public:
        int salary;
        Employee(int s)
        {
            salary = s;
        }

        void operator --()
        {
            --salary;
        }
        void operator --(int)
        {
            salary--;
        }
};

int main()
{
    Employee e(2000);
    cout << "\n salary before pre and post decrement :" << e.salary;
    --e;
    cout << "\n salary after pre decrement :" << e.salary;
    e--;
    cout << "\n salary after post decrement :" << e.salary;
    return 0;
}