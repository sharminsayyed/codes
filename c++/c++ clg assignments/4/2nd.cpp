/*Write a c++ program that determines a given number is prime or nor .(use Dynamic Constructor to
allocate and Destructor to free memory of an object*/
#include<iostream>

using namespace std;
class prime
{
    public:
        int *p;
        prime(int n)
        {
            p = new int(n);
        }
        void primenumber ()
        {
            int i, f = 0;

            if (*p == 1 || *p==0)
                f = 1;
            for ( i = 2; i < *p/2; i++)
            {
                if(*p %i == 0)
                {
                    f = 1;
                    break;
                }
            }

            if(f==1)
                cout << endl<< *p << " is not a prime number ";
            else
                 cout << endl<< *p << " is a prime number ";

        }

        ~prime()
        {
            delete (p);
            cout << "\n deleted the allocated memory";
        }

};
int main()
{
    int n;
    cout << "enter the number to be checked :";
    cin >> n;
    prime n1(n);
    n1.primenumber();

    return 0;
}