/*
Write a C++ program to design a class complex to represent complex number. The complex class
uses an external function (as a friend function) to add two complex number. The function should
return an object of type complex representing the sum of two complex Numbers. 
*/

#include<iostream>

using namespace std;

class complex{
    public:
        int real, img;
        complex(){
            
        }
        complex(int r ,int i)
        {
            real = r;
            img = i;
        }

        friend complex sum(complex c1, complex c2);
};

complex sum(complex c1 , complex c2)
{
    // complex is a datatype also
    complex c3;
    c3.real = c1.real + c2.real;
    c3.img = c1.img + c2.img;
    return c3;
}

int main()
{
    int r1, i1, r2, i2;
    cout << "\n enter the real and img part for complex no 1:";
    cin >> r1 >> i1;
    cout << "\n enter the real and img part for complex no 2:";
    cin >> r2 >> i2;

    complex n1(r1, i1);
    complex n2(r2, i2);
    complex n3;
    n3 = sum(n1, n2);
    cout<< "\n addition of 2 complex no :" << n3.real << " + " << n3.img << "i";
    return 0;
}