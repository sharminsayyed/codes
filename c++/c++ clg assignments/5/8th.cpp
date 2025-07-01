/*
Write a C++ program to subtract two integer numbers of two different classes using friend
function
*/

#include<iostream>

using namespace std;
class B;
class A{
    private:
        int x;
    public:
        A(int n)
        {
            x = n;
        }

        friend void sub(A n1, B n2);
};

class B{
    private:
        int y;
    public:
        B(int n)
        {
            y = n;
        }

        friend void sub(A n1, B n2);
};

void sub(A n1 ,B n2)
{
    int s = n1.x - n2.y;
    cout << "subtraction is :" << s;
}
int main()
{
    int m, n;
    cout << "\nenter 2 numbers:";
    cin >> m >> n;
    A num1(m);
    B num2(n);

    sub(num1, num2);
    // num1 num2 == are object names 
    return 0;
}