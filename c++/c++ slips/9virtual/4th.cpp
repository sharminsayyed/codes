/*
Create a base class Media. Derive two different classes Book (Book_id, Book_name,
Publication, Author, Book_price) and CD (CD_title, CD_price) from Media. Write a program
to accept and display information of both Book and CD. (Use pure virtual function)
*/
/*overriding and pure virtual function :*/
#include<iostream>

using namespace std;
class media{
    public:
        void virtual accept() = 0;
        void virtual display() = 0;
};
class book : public media{
    public:
        int bid, bpri;
        string bnm, bpub, bau;
        void accept()
        {
            cout << "\n enter book id, name ,publication ,author ,prize:";
            cin >> bid >> bnm >> bpub >> bau >> bpri;
        }
        void display()
        {
            cout << "\n book id:" << bid << "\n name :" << bnm << "\npublication :" << bpub << "\nauthor: " << bau << "\n prize :" << bpri << endl;
            ;
        }
};
class cd:public media{
    public:
        string ct;
        float cp;
        void accept()
        {
            cout << "\n enter cd title and price:";
            cin >> ct >> cp;
        }
        void display()
        {
            cout << "\n cd title :" << ct << "\n cd prize :" << cp;
        }
};

int main()
{
    book b;
    cd c;
    cout << "\n details of boooks :";
    b.accept();
    b.display();
    cout << "\n details of cd :";
    c.accept();
    c.display();
    return 0;
}