/*
Write a C++ program to create a class Date which contains three data members as dd, mm, and yyyy. 
Create and initialize the object by using parameterized constructor and display date in dd-mon-yyyy 
format. (Input: 19-12-2014 Output: 19-Dec-2014) Perform validation for month
*/

#include<iostream>

using namespace std;

class Date
{
    public:
        int dd, mm, yyyy;
        Date(int date ,int month ,int year)
        {
            dd = date;
            mm = month;
            yyyy = year;
        }

        void dispalydate()
        {
            int c = mm;
            string mon;
            switch (c)
            {
            case 1:
                mon = "JAN";
                break;
            
            case 2:
                mon = "FEB";
                break;

            case 3:
                mon = "MAR";
                break;

            case 4:
                mon = "APR";
                break;

            case 5:
                mon = "MAY";
                break;
            
            case 6:
                mon = "JUN";
                break;
            
            case 7:
                mon = "JULY";
                break;

            case 8:
                mon = "AUG";
                break;

            case 9:
                mon = "SEPT";
                break;
            
            case 10:
                mon = "OCT";
                break;

            case 11:
                mon = "NOV";
                break;

            case 12:
                mon = "DEC";
                break;

            default:
                cout << "\n invalid month";
                break;
            }

            cout << "\n date:" << dd << "-" << mon << "-" << yyyy;

        }
};
int main()
{
    int date, month, year;
    cout << "\n enter day:";
    cin >> date;
    cout << "\n enter month:";
    cin >>month ;
    cout << "\n enter year:";
    cin >> year;
    cout << "\n date :" << date << "-" << month << "-" << year;
    Date d1(date, month, year);
    d1.dispalydate();

    return 0;
}