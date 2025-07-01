/*
Design a base class Product(Product _Id, Product _Name, Price). Derive a class Discount
(Discount_In_Percentage) from Product. A customer buys n Products. Calculate total price,
total discount and display bill using appropriate manipulators.
*/

/*
Definition: Inheritance is one of the feature of Object Oriented Programming System (OOPs) it allows the 
child class to acquire the properties (the data members) and functionality (the member functions) of parent 
class.

single inheritance :In single inheritance, a class is allowed to inherit from only one base class. i.e. one sub 
class is inherited by one base classonly 
*/
#include<iostream>

using namespace std;
class product{
    public:
        int pid;
        string pnm;
        float pp;
        void accept()
        {
            cout << "\nenter the prooduct id , name ,prize :";
            cin >> pid >> pnm >> pp;
        }
        void display()
        {
            cout << "\n product id :" << pid << "\n name :" << pnm << "\n prize :" << pp;
        }
};

class discount : public product{
    public:
        float dper;
        void accept()
        {
            product ::accept();
            cout<< "\n enter the discount in percentage :";
            cin >> dper;
        }
        void display()
        {
            product::display();
            cout << "\n discount in percentage :" << dper;
            cout << endl;
        }

        void cal_bill(discount d[] , int n)
        {
            float tp = 0, td = 0, tb = 0;
            int i;
            for ( i = 0; i < n; i++)
            {
                tp = tp + d[i].pp;
                td = td + ((d[i].dper * d[i].pp) / 100); // impptttt lineeeee

            }
            tb = tp + td;
            cout << "\n total price :" << tp << "\n total discount :" << td << "\n------------------------";
            cout << "\n total bill :" << tb << endl;
        }
};
int main()
{
    int n,i;
    cout << "\n enter the no of products :";
    cin >> n;
    discount d[n] ,s;
    for ( i = 0; i < n; i++)
    {
        d[i].accept();
    }
    for ( i = 0; i < n; i++)
    {
        d[i].display();
    }

    s.cal_bill(d, n);

    return 0;
}