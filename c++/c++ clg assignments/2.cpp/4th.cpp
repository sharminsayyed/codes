/*. Write a C++ program to create a class District. Having district_code, district_name, area_sqft, population, 
literacy_rate. For displaying details use appropriate manipulators. The program should contain following 
menu :
a. Accept details of n district
b. Display details of district.
c. Display details of district having highest literacy rate.
d. Display details of district having least population.
*/
#include<iostream>
using namespace std;

class district{
    public:
        int dc, da, dp, dl;
        string dnm;
        void accept();
        void display();
};

void district ::accept()
{
    cout << "\nenter district code :";
    cin >> dc;
    cout << "\nenter district name :";
    cin >> dnm;
    cout << "\nenter district area sqfeet :";
    cin >> da;
    cout << "\nenter district population :";
    cin >> dp;
    cout << "\nenter district literacy rate :";
    cin >> dl;

}
void district ::display()
{
     cout << "\ndistrict code:" <<dc  << "\n name:" << dnm << "\n areasqft:" << da<< "\npopulation:" << dp << "\nliteracy rate:" <<dl ;
     cout << endl;
}

int main()
{
    district d[10];
    int n, ch, i;
    int maxlr, minp;
    cout << "\nhow many district :";
    cin >> n;
    while(1)
    {
        cout << "\n menu :1 Accept details of n district\n2 Display details of district.\n3 Display details of district having highest literacy rate.\n4 Display details of district having least population\n";
        cout << "\n enter ur choice :";
        cin >> ch;
        
            switch(ch)
            {
                case 1:
                    for (i = 0; i < n;i++)
                     d[i].accept();
                        break;
    
                case 2:
                    for (i = 0; i < n;i++)
                        d[i].display();
                        break;

                case 3:
                    maxlr = d[0].dl;
                    for (i = 0; i < n;i++)
                    {
                        if(d[i].dl > maxlr)
                            maxlr = d[i].dl;
                    }

                    for ( i = 0; i < n; i++)
                    {
                        if(d[i].dl == maxlr)
                            d[i].display();
                    }

                        break;

                case 4:
                    minp = d[0].dp;
                    for ( i = 0; i < n; i++)
                    {
                        if(d[i].dp < minp)
                            minp = d[i].dp;
                    }
                    for ( i = 0; i < n; i++)
                    {
                        if(d[i].dp == minp)
                            d[i].display();
                    }
                        break;

                    default:
                        cout << "\n invalid input";
                        exit(0);
                        break;
            }
        
    }

    
}