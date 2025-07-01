/*
Write a C++ program to create a class Mobile which contains data members as Mobile_Id, 
Mobile_Name, Mobile_Price. Create and Initialize all values of Mobile object by using parameterized 
constructor. Display the values of Mobile object where Mobile_price should be right justified with a 
precision of two digits.
*/
#include<iostream>

using namespace std;
class MObile{
    public:
        int mid;
       float mprice;
        string mname;
        MObile(int moid , float moprice ,string moname)
        {
            mid = moid;
            mprice = moprice;
            mname = moname;
        }

        void display()
        {
            cout << "\n mobile id :" << mid;
            cout << "\n mobile name :" << mname;
            cout << "\n mobile price :" << mprice;
        }
};
int main()
{
    int moid;
    float moprice;
    string moname;
    cout << "\n enter the mobile id :" ;
    cin >> moid;
    
    cout << "\n enter the mobile name :"  ;
    cin >>moname ;
    cout << "\n enter the mobile price :"  ;
    cin >>moprice ;

    MObile m1(moid, moprice, moname);
    m1.display();

    return 0;
}