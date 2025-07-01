/*
.Create a base class Student (Roll_No, Name) which derives two classes Theory and Practical.
Theory class contains marks of five Subjects and Practical class contains marks of two practical
subjects. Class Result (Total_Marks, Class) inherits both Theory and Practical classes. (Use
concept of Virtual Base Class) Write a menu driven program to perform the following functions:
a. Build a master table.
b. Display master table
*/
/*virtual base class :*/
#include<iostream>

using namespace std;
class student{
    public:
        int srn;
        string snm;
        void get()
        {
            cout << "\n enter rollno and name :";
            cin >> srn >> snm;
        }
        void put()
        {
            cout << "|"<< " student roll no : " << srn << "|"<< "name : " << snm << "|";
        }
};
class theory : virtual public student{
    public:
        int m1, m2, m3, m4, m5;
        void getth()
        {
            cout << "\n enter the marks of 5 theory subjects :";
            cin >> m1 >> m2 >> m3 >> m4 >> m5;
        }
        void putth()
        {
            cout << "marks1 : " << m1 << "|"
                 << "marks2 : " << m2 << "|"<< "marks3 : " << m1 << "|"
                 << "marks3 : " << m1 << "|"<< "marks4 : " << m4 << "|"<< "marks5 : " << m5 << "|";
        }
};
class practical : virtual public student{
    public:
        int p1, p2;
        void getp()
        {
            cout << "\n enter the marks of 2 practical subjects :";
            cin >> p1 >> p2;
        }
        void putp()
        {
            cout << "prac marks 1 :" << p1 << "|"
                 << "prac marks 2 :" << p2 << "|";
        }
};

class result : public theory , public practical{
    public:
        int tm;
        string cls;
        void display()
        {
            tm = m1 + m2 + m3 + m4 + m5 + p1 + p2;
            float per = (tm / 7);// (tm / 700)*100
            if( per >= 70)
                cls = "first class with distinction";
            else if(per >= 60)
                cls = "first class";
            else if(per >= 50)
                cls = "second class";
            else if(per >=40)
                cls = "pass";
            else
                cls = "fail";

            cout << "total marks : " << tm << "|"
                 << "class : " << cls << "|";
        }
};
int main()
{
    int ch;
    result r;
    while(1)
    {
        cout << "\n menu : \n1) Build a master table.\n2) Display master table";
        cout << "\n enter ur choice :";
        cin >> ch;
        cout << "\n -------------------------------------------------------------------- \n";
        switch (ch)
        {
        case 1:
            r.get();
            r.getth();
            r.getp();
            break;
        
        case 2:
            r.put();
            r.putth();
            r.putp();
            r.display();
            break;
        default:
            cout << "\n invlaid output";
            exit(0);
            break;
        }
    }

    return 0;
}