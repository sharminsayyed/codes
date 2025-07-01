/*
Write a C++ program to create two classes Rectangle1 and Rectangle2. Compare area of both the
rectangles using friend function.
*/

/*
syntax to write friend return_type function_name (class name objectname);
in friend function data members are private or protected 
*/
#include<iostream>

using namespace std;

class rectangle2;
class rectangle1
{
    private:
        float l1, w1;
        float area1;
    public:
        rectangle1(float len1 , float wid1)
        {
            l1 = len1;
            w1 = wid1;
            area1 = l1 * w1;
            cout << "\n area of rectangle 1:" << area1;
        }

        friend void compare(rectangle1 r1, rectangle2 r2);
};

class rectangle2
{
    private:
        float l2, w2;
        float area2;
    public:
        rectangle2(float len2,float wid2)
        {
            l2 = len2;
            w2 = wid2;
            area2 = l2 * w2;
            cout << "\n area of rectangle 2:" << area2;
        }

        friend void compare(rectangle1 r1, rectangle2 r2);
};

void compare(rectangle1 r1 , rectangle2 r2)
{
    if(r1.area1 > r2.area2)
        cout << "\n Area of rectangle 1 is greater than Area of rectangle 2";
    else
        cout << "\n Area of rectangle 2 is greater than Area of rectangle 1";

}
int main()
{
    float len1, len2, wid1, wid2;
    cout << "\n enter the length and width of rectangle 1:";
    cin >> len1 >> wid1;
    cout << "\n enter the length and width of rectangle 2:";
    cin >> len2 >> wid2;

    rectangle1 n1(len1, wid1);
    rectangle2 n2(len2, wid2);
    compare(n1, n2);// calling friend function

    return 0;
}