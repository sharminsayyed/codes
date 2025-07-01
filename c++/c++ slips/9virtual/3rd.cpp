/*
2. A book (ISBN) and CD (data capacity) are both types of media (id, title) objects. A person buys
10 media items each of which can be either book or CD. Display the list of all books and CD’s
bought. Define the classes and appropriate member functions to accept and display data. Use
pointers and concept of polymorphism (Virtual Function)
*/
/*pure virtual function*/
#include<iostream>

using namespace std;
class media{
    public:
        int id;
        string t;
        virtual void accept() = 0;
        virtual void display() = 0;
};
class book : virtual public media{
    public:
        int isbn;
        void accept()
        {
            cout << "\n enter book id, title , isbn :";
            cin >> id >> t >> isbn;
        }
        void display()
        {
            cout << "\n book id :" << id << "\n title :" << t << "\n isbn :" << isbn << endl;
        }
};
class cd : virtual public media{
    public:
        int cap;
        void accept()
        {
            cout << "\n enter cd id, title , capacity:";
            cin >> id >> t >> cap;
        }
        void display()
        {
            cout << "\n cd id :" << id << "\n title :" << t << "\n capacity :" << cap << endl;
        }
};

int main()
{
    int i, l1, l2;
    cout << "\n how many books person purchased :";
    cin >> l1;
    book b[l1];// array of objects
    l2 = 10-l1;
    // array of objects
    cd c[l2];
    // pointer of array of objects
    media *m[10];

    for ( i = 0; i < l1; i++)
    {
        m[i] = &b[i];
        m[i]->accept();
    }
    int j = 0; // m[i] will continue the array after book 
    // but cd will start from new address that is 0
    for ( i = l1; i < 10; i++)
    {
        m[i] = &c[j];
        m[i]->accept();
        j++;
    }

    cout << "\n detials of all books purchased :";
    for ( i = 0; i < l1; i++)
    {
        m[i]->display();
    }
    cout << "\n details of all cds purchased :";
    for ( i = l1; i < 10; i++)
    {
        m[i]->display();
    }
    

    return 0;
}