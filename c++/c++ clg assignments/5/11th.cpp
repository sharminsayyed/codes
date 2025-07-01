/*
.Create a class College containing data members as College_Id, College_Name,
Establishment_year, University_Name. Write a C++ program with following functions
a. Accept n College details
b. Display College details of specified University
c. Display College details according to Establishment year (Use Array of Objects and
Function Overloading)
*/

#include<iostream>

using namespace std;
class college{
    public:
        int cid, cy;
        string cnm, cun;
        int i;
        void accept(college c[], int n)
        {
            for ( i = 0; i < n; i++)
            {
                cout << "\n enter college id , name, establishment year , university name :";
                cin >> c[i].cid >> c[i].cnm >> c[i].cy >> c[i].cun;
            }

            cout << "\n displaying all college details\n";
            for ( i = 0; i < n; i++)
            {
                cout << "\n college id:" << c[i].cid << "\n college name:" << c[i].cnm << "\n establishment year :" << c[i].cy << "\n university name:" << c[i].cun;
                cout << endl;
            }
            
        }

        void display(college c[], int n,string uni)
        {
            int f = 0;
            for (size_t i = 0; i < n; i++)
            {
               if(c[i].cun == uni)
               {
                    cout << "\n college id:" << c[i].cid << "\n college name:" << c[i].cnm << "\n establishment year :" << c[i].cy << "\n university name:" << c[i].cun;
                    f = 1;
                    break;
               }
            }
            if(f==0)
                cout << "\n college of this university not found";
        }

        void display(college c[] ,int n ,int year)
        {
            int f = 0;
            for ( i = 0; i < n; i++)
            {
                if(c[i].cy == year)
                {
                    cout << "\n college id:" << c[i].cid << "\n college name:" << c[i].cnm << "\n establishment year :" << c[i].cy << "\n university name:" << c[i].cun;
                    f = 1;
                    break;
                }
            }
            if(f==0)
                cout << "\n college of that year not found";
        }

};
int main()
{
    int n,ch;
    string uni;
    int year;
    cout << "\n enter the no of college:";
    cin >> n;
    college c[n]; // to pass as argument for the function
    college s; // to use as object to acces all functions of class
    

    while(1)
    {
        cout << "\n menu : \na. Accept n College details\nb. Display College details of specified University\nc. Display College details according to Establishment year";
        cout << "\n enter the choice :";
        cin >> ch;
        switch (ch)
        {   
            case 1:
                s.accept(c, n);
                break;
            case 2:
                cout << "\n enter the name of university :";
                cin >> uni;
                s.display(c, n, uni);
                break;

            case 3:
                cout << "\n enter the establishment year :";
                cin >> year;
                s.display(c, n, year);
                break;
            default:
                cout << "invalid input";
                exit(0);
                break;
        }
    }

    return 0;
}