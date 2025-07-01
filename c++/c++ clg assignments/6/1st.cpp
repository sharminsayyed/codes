// operator overloading 
/*
Write a C++ program to create a class Array that contains one float array as member. Overload
the Unary ++ and -- operators to increase or decrease the value of each element of an array. Use
friend function for operator function.*/

#include<iostream>

using namespace std;

class array{
    public:
        float a[10];
        int i, n;

        void accept()
        {
            cout << "enter the no of element:";
            cin >> n;
            for (i = 0; i < n;i++)
            {
                cout << "index " << i + 1 << ":";
                cin >> a[i];
            }
        }

        void display()
        {
            cout << "array :";
            for ( i = 0; i < n; i++)
            {
                cout << a[i] << "\t";
            }
            
        }

        friend void operator ++(array& obj);
        friend void operator --(array& obj);
};

void operator ++(array& obj)
{
    for (int i = 0; i < obj.n; i++)
    {
        obj.a[i]++;
    }
    
}

void operator --(array& obj)
{
    for (int i = 0; i < obj.n; i++)
    {
        obj.a[i]--;
    }
    
}
int main()
{
    array b;
    b.accept();
    b.display();

    ++b;
    cout << "\n after incrementing array :";
    b.display();

    --b;
    cout << "\n after decrementing array :";
    b.display();
    return 0;
}