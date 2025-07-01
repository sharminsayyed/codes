/*
.Create a base class Flight containing protected data members as Flight_no, Flight_Name. Derive
a class Route(Source, Destination) from class Flight. Also derive a class Reservation (no_seats,
class, fare, travel_date) from Route. Write a C++ program to perform the following necessary
functions.
a. Enter details of n reservations.
b. Display reservation details of Business class.
*/
/* multilevel inheritance :In this type of inheritance, a derived class is created from another derivedclass.
*/

#include<iostream>

using namespace std;
class flight{
    protected:
        int fno;
        string fnm;
    public:
        void accept()
        {
            cout << "\n enter the flight no and name :";
            cin >> fno >> fnm;
        }
};
class route :public flight{
    public:
        string src, dest;
        void accept()
        {
            flight::accept();
            cout << "\n enter the sorce and destination :";
            cin >> src >> dest;
        }
};
class reservation : public route {
    public:
        int nfs;
        string cls;
        float fare;
        void accept()
        {
            route ::accept();
            cout << "\n enter no of seats , class , fare :";
            cin >> nfs >> cls >> fare;
        }

        void de_bsn(reservation r[] ,  int n)
        {
            for (int i = 0; i < n; i++)
            {
                if(r[i].cls == "business")
                {
                    cout << "\nflight no :" << r[i].fno << "\nflight name :" << r[i].fnm << "\nsource :" << r[i].src << "\ndesination :"
                         << r[i].dest << "\nno of seats :" << r[i].nfs << "\nclass :" << r[i].cls << "\nfare :" << r[i].fare << endl;
                }
            }
            
        }
};
int main()
{
    int n;
    cout << "enter the no of reservation :";
    cin >> n;
    reservation r[n], s;
    for (int i = 0; i < n; i++)
    {
        r[i].accept();
    }

    cout << "\n details of  business class flights :";
    s.de_bsn(r, n);
    return 0;
}