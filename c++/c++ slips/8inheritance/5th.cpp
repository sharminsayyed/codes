/*
Design a two base classes Employee (Name, Designation) and Project(Project_Id, title).
Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven
program to
a. Build a master table.
b. Display a master table
c. Display Project details in the ascending order of duration
*/

/* mutiple inheritance :: Multiple Inheritance is a feature of C++ where a class can inherit from more than one 
classes. i.e one sub class is inherited from more than onebaseclasses  */
#include<iostream>
#include<iomanip>
using namespace std;
class employee{
    public:
        string enm;
        string edesg;
        void accept()
        {
            cout << "\nenter the employee name and designation :";
            cin >> enm >> edesg;
        }
        void display()
        {
            cout << "|"<<setw(15)<< enm << "|" <<setw(15)<< edesg << "|";
        }
};
class project {
    public:
        int pid;
        string pt;
        void accept()
        {
            cout << "\n enter project id,title :";
            cin >> pid >> pt;
        }
        void display()
        {
            cout <<setw(15)<< pid << "|" <<setw(15)<< pt << "|";
        }
};
class emp_proj: public employee,public project{
    public:
        int dur;
        void accept()
        {
            employee::accept();
            project::accept();
            cout << "enter duration :";
            cin >> dur;
        }
        void display()
        {
            employee::display();
            project::display();
            cout <<setw(15)<< dur;
            cout << endl;
        }

        void ascsort(emp_proj p[] ,int n)
        {
            int i, j;
            emp_proj temp;
            for ( i = 0; i < n; i++)
            {
                for (j = i+1; j < n;j++)
                {
                    if(p[i].dur > p[j].dur)
                    {
                        temp = p[i];
                        p[i] = p[j];
                        p[j]= temp;
                    }
                }
            }
            
        }

};
int main()
{
    int n,ch,i;
    cout << "\n how many projects :";
    cin >> n;
    emp_proj p[n], s;
    while(1)
    {
        cout << "\n menu :\na. Build a master table.\nb. Display a master table\nc. Display Project details in the ascending order of duration";
        cout << "\nenter ur choice :";
        cin >> ch;
        cout << "\n---------------------------------------------------------\n";
        switch(ch)
        {
            case 1 :
                for (i = 0; i < n;i++)
                {
                    p[i].accept();
                }
                break;

            case 2 :
                for (i = 0; i < n;i++)
                {
                    p[i].display();
                }
                break;
            case 3 :
                s.ascsort(p, n);
                for (i = 0; i < n;i++)
                {
                    p[i].display();
                }
                break;
            default:
                cout << "\n invalid choice :";
                exit(0);
        }
    }
    return 0;
}