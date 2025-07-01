/*
Write a C++ program to define a class Bus with the followingspecifications :
 Bus No
 Bus Name
 No of Seats
 Starting point
 Destination
Write a menu driven program by using appropriate manipulators to
a. Accept details of n buses.
b. Display all busdetails.
c. Display details of bus from specified starting and ending destinationbyuser.
*/

#include<iostream>

using namespace std;

class bus{
    public:
        int bno, bseat;
        string bname, bstart, bdest;
        void accept();
        void display();
};

void bus :: accept()
{
    cout << "\nenter the bno :";
    cin >> bno;
    cout << "\n enter bus name :";
    cin >> bname;
    cout << "\nenter no of searts :";
    cin >> bseat;
    cout << "\nenter the starting point:";
    cin >> bstart;
    cout << "\nenter the destination :";
    cin >> bdest;
}

void bus ::display()
{
    cout << "\nbus no:" << bno << "\nbus name:" << bname << "\nno of seats:" << bseat << "\nstarting point:" << bstart << "\ndestination:" << bdest;
    cout << endl;
}

int main()
{
    bus b[10];
    // created an array of object which stores property of class bus
    int n, i, ch;
    string s, d;
    cout << "\n how many buses :";
    cin >> n;
    while(1)
    {
    cout<<endl<<"menu : 1)accept details of bus \n 2) display details of buses \n 3) Display details of bus from specified starting and ending destinationbyuser.\n ";
    cout << "enter the choce :";
    cin >> ch;
    switch (ch)
    {
    case 1:
        for (i = 0; i < n;i++)
            b[i].accept();
            break;
    
    case 2:
        for (i = 0; i < n;i++)
            b[i].display();
            break;
    
    case 3:
        cout << "\nenter the starting point :";
        cin >> s;
        cout << "\n enter the destination :";
        cin >> d;
        for (i = 0; i < n;i++)
        {
            if((b[i].bstart == s) && (b[i].bdest == d) )
                b[i].display();
            else
                cout << "\n not found ";
        }

            break;

    default :
        cout << "\n invalid input";
        exit(0);
        break;
        }
    }
    return 0;
}