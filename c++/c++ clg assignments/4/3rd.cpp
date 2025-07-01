/*
Write a C++ Program to store GPA of a number of students and display it where n is thenumber of students 
entered by the use*/
#include<iostream>

using namespace std;

class gpa
{
    public:
        int *p;
        int i, num;
        gpa(int n)
        {
            num = n;
            p = new int[num];
            cout << "\n array of student gpa is created";
        }

        void accept()
        {
            for ( i = 0; i < num; i++)
            {
                cout << "\nenter gpa of stuetnt " << i + 1 << ":";
                cin >> p[i];
            }
            
        }

        void display()
        {
            for ( i = 0; i < num; i++)
            {
                cout << "\ngpa of student  " << i + 1 << ":" << p[i];
            }
            
        }

        ~gpa()
        {
            delete[] p;
            cout << "\n array destroyed";
        }
};
int main()
{
    int n;
    cout << "enter the no of student :";
    cin >> n;
    gpa n1(n);
    n1.accept();
    n1.display();

    return 0;
}