/*
. Create a Base class Train containing protected data members as Train_no, Train_Name. Derive a
class Route(Route_id, Source, Destination) from Train class. Also derive a class Reservation
(Number_of_Seats, Train_Class, Fare, Travel_Date) from Route. Write a C++ program
to perform following necessary functions:
a. Enter details of n reservations
b. Display details of all reservations
c. Display reservation details of a specified Train class
*/
#include<iostream>

using namespace std;
class train {
    protected:
        int tno;
        string tnm;
    public:
        void accept()
        {
            cout << "\n enter the train no ,name :";
            cin >> tno >> tnm;
        }

        void display()
        {
            cout << "\n train no :" << tno << "\n name :" << tnm;
        }
};
class route  : public train{
    public:
        int rid;
        string src, dest;
        void accept()
        {
            train::accept();
            cout << "\n enter the route id ,source,destination : ";
            cin >> rid >> src >> dest;
        }
        void display()
        {
            train ::display();
            cout << "\n route id :" << rid << "\n source :" << src << "\n destination :" << dest;
        }
};

class reservre : public route{
    public:
        int nfs;
        string cls;
        float fare;
        void accept()
        {
            route::accept();
            cout << "\n enter no of seats , class , fare :";
            cin >> nfs >> cls >> fare;
        }
        void display()
        {
            route::display();
            cout << "\n no of seats :" << nfs << "\n class :" << cls << "\n fare :" << fare;
        }

        void det_cls(reservre r[] , int n , string spcls)
        {
            for (int i = 0; i < n; i++)
            {
                if(r[i].cls == spcls)
                {
                    cout << "\ntrain no :" << r[i].tno << "\nflight name :" << r[i].tnm << "\nsource :" << r[i].src << "\ndesination :"
                         << r[i].dest << "\nno of seats :" << r[i].nfs << "\nclass :" << r[i].cls << "\nfare :" << r[i].fare << endl;

                }
            }
            
        }
};

int main()
{
    int n, i;
    string spcls;
    cout << "\n enter the no of reservation :";
    cin >> n;
    reservre r[n], s;
    for ( i = 0; i < n; i++)
    {
        r[i].accept();
    }
    cout << "\n details of all reservation :";
    for ( i = 0; i < n; i++)
    {
        r[i].display();
    }
    cout << "\n----------------------------------\n";
    cout << "\n enter the specific class :";
    cin >> spcls;
    s.det_cls(r, n, spcls);
    return 0;
}