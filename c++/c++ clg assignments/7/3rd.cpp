/*
Create two base classes Learn_Info(Roll_No, Stud_Name, Class, Percentage) and
Earn_Info(No_of_hours_worked, Charges_per_hour). Derive a class Earn_Learn_info from
above two classes. Write necessary member functions to accept and display Student
information. Calculate total money earned by the student. (Use constructor in derived class)
*/

#include<iostream>

using namespace std;
class learn_info{
    public:
        int srn;
        string snm, scls;
        float sper;
        learn_info(int rn, string nm, string cls, float per)
        {
            srn = rn;
            snm = nm;
            scls = cls;
            sper = per;
        }
        void display()
        {
            cout << "\n detials about student : "
                 << "\n student roll no :" << srn << "\nname :" << snm << "\n class :" << scls << "\npercentage :" << sper << "%\n";
        }
};
class earn_info
{
    public:
        int snfh, sch;
        earn_info(int nfh , int ch)
        {
            snfh = nfh;
            sch = ch;
        }
        void display()
        {
            cout << "\n details about earning :";
            cout << "\n no of hours worked :" << snfh << "\n charges per hour :" << sch;
        }
        void cal()
        {
            cout << "\n total money earned by student :" << snfh * sch;
        }
};

class earn_learn_info :public learn_info,public earn_info
{
    public:
    earn_learn_info(int rn , string nm,string cls ,float per ,int nfh ,int ch) :learn_info(rn,nm,cls,per) , earn_info(nfh ,ch)
    {  // nothing here
    }

    void display()
    {
        learn_info::display();
        earn_info::display();
    }
};
int main()
{
    int rn, nfh, ch;
    string nm, cls;
    float per;
    cout << "\n enter student roll no , name, class,percentage ,no of hours ,charges per hours: ";
    cin >> rn >> nm >> cls >> per >> nfh >> ch;
    earn_learn_info p(rn, nm, cls, per, nfh, ch);
    p.display();
    p.cal();

    return 0;
}