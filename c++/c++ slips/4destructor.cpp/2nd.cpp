/*
Write a C++ program to create a class which contains single dimensional integer array of given size. 
Define member function to display median of a given array. (Use Dynamic Constructor to allocate and 
Destructor to free memory of anobject)*/

#include<iostream>

using namespace std;

class median
{
    public:
        int *p;
        int num,i;
        median(int n)
        {
            num = n;
            p = new int[num];
            cout << "\n array created ";
        }

        void accept()
        {
            for (size_t i = 0; i < num; i++)
            {
                cout << "\n index" << i + 1 << ":";
                cin >> p[i];
            }
            
        }


        void mediann()
        {
            // sort i first
            int j,temp;
            for ( i = 0; i < num; i++)
            {
                for ( j = i+1; j < num; j++)
                {
                    if(p[i] > p[j])
                    {
                        temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                    }
                }
                
            }

            cout << "\n display sorted array";
            for ( i = 0; i < num; i++)
            {
                cout << endl<< p[i] << "\t";
            }

            // median logic =lower+upper /2 ---even-- =middle element =odd

            int l, u, m;
            if(num %2 ==0)
            {
                l = p[num / 2];
                u = p[(num / 2) - 1];
                m = (l + u) / 2;
                cout << "\n median for even number of array :" << m;
            }

            else{
                l = p[num / 2];
                cout << "\n median for odd number of array :" << l;
            }
            
        }

        ~median()
        {
            delete[] p;
            cout << "\n deleted memory";
        }
};
int main()
{
    int n;
    cout << "\n enter the number:";
    cin >> n;
    median m1(n);
    m1.accept();
    m1.mediann();
    return 0;
}