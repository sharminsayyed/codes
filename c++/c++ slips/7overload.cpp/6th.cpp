/*
Write a C++ program to sort integer and float array elements in ascending order by using
function overloading
*/

#include<iostream>

using namespace std;

class arrsort{
    public:
        int i, j, temp;
        void sort_array(int a[], int n)
        {
            for ( i = 0; i < n; i++)
            {
                for (j = i + 1; j < n;j++)
                {
                    if(a[i]>a[j])
                    {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }

            cout << "\n display the ascending sort integer array :";
            for ( i = 0; i < n; i++)
            {
                cout << a[i] << "\t";
            }
            
        }

        void sort_array(float b[] , int n)
        {
            float tempp;
            // float i, j;
            for ( i = 0; i < n; i++)
            {
                for (j = i+1; j < n;j++)
                {
                    if(b[i]>b[j])
                    {
                        tempp = b[i];
                        b[i] = b[j];
                        b[j] = tempp;
                    }
                }
            }
            

            cout << "\n display the ascending sort float array :";
            for ( i = 0; i < n; i++)
            {
                cout << b[i] << "\t";
            }
            
        }
};
int main()
{
    int a[10] = {12, 34, 56, 1, 2, 3};
    float b[10] = {23.34, 34.12, 1.23, 4.56, 45.01, 90.00, 2.34};
    arrsort a1;
    a1.sort_array(a,6);
    a1.sort_array(b, 7);

    return 0;
}