/*
Create a class Book containing Book_name, author and Price as a data member and write
necessary member functions for the following (use function overloading).
a. To Accept and display the Book Information.
b. Display book details of a given author
c. Display book details of specific price [20]
*/

#include<iostream>

using namespace std;
class Book{
    public:
        string bnm,ba;
        float bp;
        int i;
        void accept(Book b[],int n)
        {
            // book b[] == array of objects
            for ( i = 0; i < n; i++)
            {
                cout << "\n enter book name , author , price :";
                cin >> b[i].bnm >> b[i].ba >>b[i].bp;
            }

            cout << "\n display the book information of all objects";

            for ( i = 0; i < n; i++)
            {
                cout << "\n book name:" << b[i].bnm << "\n book author:" << b[i].ba << "\n book price :" << b[i].bp;
                cout << endl;
            }
            
        }

        void display(Book b[] ,int n, string author)
        {
            int f = 0;
            for ( i = 0; i < n; i++)
            {
                if(b[i].ba == author)
                {
                    cout << "\n book name:" << b[i].bnm << "\n book author:" << b[i].ba << "\n book price :" << b[i].bp;
                    f = 1;
                    break;
                }
                
            }
            if (f==0)
                cout << "\n book not found";
        }

        void display(Book b[],int n, float price)
        {
            int f = 0;
            for ( i = 0; i < n; i++)
            {
                if(b[i].bp == price)
                {
                    cout << "\n book name:" << b[i].bnm << "\n book author:" << b[i].ba << "\n book price :" << b[i].bp;
                    f = 1;
                    break;
                }
            
            }
            if(f==0)
                cout << "\n book not found";
        }
};
int main()
{
    int n, ch;
    string author;
    float price;
    
    cout << "\nhow many books :";
    cin >> n;
    Book b[n]; // to pass as argument for the function
    Book s; // to use as object to acces all functions of class
    while(1)
    {
        cout << "\nmenu :\na. To Accept and display the Book Information.\nb. Display book details of a given author\nc. Display book details of specific price";
        cout << "\nenter ur choice:";
        cin >> ch;
        switch (ch)
        {
            case 1:
                s.accept(b, n);
                break;
            case 2:
                cout << "\nenter the author name:";
                cin >> author;
                s.display(b, n, author);
                break;
        
            case 3:
                cout << "\nenter the specific price :";
                cin >> price;
                s.display(b, n, price);
                break;

            default:
                cout << "invlaied input";
                exit(0);
                break;
        }
    }
    return 0;
}