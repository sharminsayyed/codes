// classes and objects only 
/*
Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price.
Write member functions to accept and display item information and also display number of objects
created for a class. (Use Static data member and Static member function) 
*/
#include<iostream>

using namespace std;

class item{
    public:
        int icode, iprice;
        string iname;
        static int cnt; 
        void accept()
        {
            cout << "\nenter  item code:";
            cin >> icode;
            cout << "\n enter item name: ";
            cin >> iname;
            cout << "\n enter item price :";
            cin >> iprice;
            cnt++;
        }
        void display()
        {
            cout << "\n item code" << icode << "\n item name :" << iname << "\nitem price" << iprice;
        }
        static void nob()
        {
            cout << endl
                 << cnt << " object created";
        }

};
int item::cnt;// by default it intializes to 0
int main()
{
    // item i1[2];
    // for (int i = 0; i < 2;i++)
    // {
    //     i1[i].accept();
    // }

    // for (int i = 0; i < 2;i++)
    // {
    //     i1[i].display();
    // }

    // ORR
    item i1, i2, i3;
    i1.accept();
    i1.display();
    item::nob();

    i2.accept();
    i2.display();
    item::nob();

    i3.accept();
    i3.display();
    item::nob();

    return 0;
}