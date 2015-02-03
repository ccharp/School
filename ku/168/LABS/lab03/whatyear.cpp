#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    bool div_by_4 = (year % 4 == 0);
    bool div_by_100 = (year % 100 == 0);
    bool div_by_400 = (year % 400 == 0);
    

    if (year >= 1500 && year <= 2400)
    {
     if (year % 4 == 0 && year % 100 != 0)
     {
        cout << "It is a leap year but not a centennial year." << endl;
     }
     else if (year % 100 == 0 && year % 4 != 0)
     {
        cout << "It is a centennial year but not a leap year." << endl;
     }
     else if (year % 400 == 0)
     {
        cout << "It is a centennial year and a leap year." << endl;
     }
     else 
     {
        cout << "It is neither a centennial year nor a leap year." << endl;
     }
    }
    else
    {
      cout<<"The year is beyond the range of 1500-2400." << endl;
    }
    return 0;
}
