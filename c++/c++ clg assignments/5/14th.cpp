/*
Write a C++ program to implement a class ‘student’ to overload following functions as follows:
a. int maximum(int, int) – returns the maximum score of two students
b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’ */

#include<iostream>

using namespace std;

class student
{
    public:
        int score;
        student(int s)
        {
            score = s;
        }
        int maximum(int a, int b)
        {
            if (a > b)
                return a;
            else
                return b;
    }

    int maximum(int *a ,int n)
    {
        int max = a[0];
        for (int i = 0; i < n; i++)
        {
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
};
int main()
{
    int a, b;
    cout << "\nenter score of student 1:";
    cin >> a;
    cout << "\nenter score of student 2:";
    cin >> b;

    student s1(a);
    student s2(b);
    cout << "max score (2) :" <<s1.maximum(s1.score, s2.score);

    int *p, n;
    cout << "\n enterr the no of array elements:";
    cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "max score (2) :" <<s1.maximum(p,n);
    return 0;
}