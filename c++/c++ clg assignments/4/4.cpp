//  see this before median proble 
#include<iostream>

using namespace std;

int main()
{
    int *p;
    p = new int[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> p[i];
    }
    // that is index 0, index1 ,index2 ,index3 index4 index5  --- even array
    int l = p[6 / 2];   // == 3  index3 will be stored // n/2
    int u = p[(6 / 2) - 1]; // == index2 will be stored
    int m = (l + u) / 2;
    cout << "\n median :" << m;

    return 0;
}