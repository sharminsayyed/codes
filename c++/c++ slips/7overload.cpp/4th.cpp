/*
Write a C++ program to create a class Person that contains data members as Person_Name, City,
Mob_No. Write a C++ program to perform following functions:
a. To accept and display Person information
b. To search the Person details of a given mobile number
c. To search the Person details of a given city.
(Use Function Overloading) 
*/

#include<iostream>

using namespace std;
class person{
    public:
        string pnm, pci;
        long long pmo;
        int i;
        void accept(person p[], int n)
        {
            for ( i = 0; i < n; i++)
            {
                cout << "\n enter person name ,city, mobile number :";
                cin >> p[i].pnm >> p[i].pci >> p[i].pmo;
            }

            cout << "\n displaying all person details :\n";
            for ( i = 0; i < n; i++)
            {
                cout << "\n person name :" << p[i].pnm << "\n person city :" << p[i].pci << "\n mobile number :" << p[i].pmo;
                cout << endl;
            }
        }

        void display(person p[], int n, int mobile)
        {
            int f = 0;
            for ( i = 0; i < n; i++)
            {
                if(p[i].pmo == mobile)
                {
                    cout << "\n person name :" << p[i].pnm << "\n person city :" << p[i].pci << "\n mobile number :" << p[i].pmo;
                    f = 1;
                    break;
                }
            }
            if(f==0)
                cout << "\n person with this mobile no not found";
        }

        void display(person p[], int n, string city)
        {
            int f = 0;
            for ( i = 0; i < n; i++)
            {
                if(p[i].pci == city)
                {
                    cout << "\n person name :" << p[i].pnm << "\n person city :" << p[i].pci << "\n mobile number :" << p[i].pmo;
                    f = 1;
                    break;
                }
            }
            if(f==0)
                cout << "\n person of this city no not found";
        }

};
int main()
{
    int n,ch;
    long long mobile;
    string city;
    cout << "\n how many person :";
    cin >> n;

    person p[n];
    person s;

    while(1)
    {
        cout << "\n menu :\na. To accept and display Person information\nb. To search the Person details of a given mobile number\nc. To search the Person details of a given city";
        cout << "\n enter ur choice :";
        cin >> ch;
        switch (ch)
        {
            case 1:
                s.accept(p, n);
                break;
        
            case 2:
                cout << "\n enter the mobile number :";
                cin >> mobile;
                s.display(p, n, mobile);
                break;
            case 3:
                cout << "\n enter the city:";
                cin >> city;
                s.display(p, n, city);
                break;
            default:
                cout << "\n invalid input";
                exit(0);
                break;
        }
    }
    return 0;
}