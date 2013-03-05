#include <iostream>
using namespace std;

int main()
{
//variables
int a, surface_area, volume; 

//user input
cout << "Please enter side length:";
cin >> a;

//compute volume and surface area
surface_area = 6 * a * a;
volume = a * a * a;
cout << "The surface area is:" << surface_area << endl;
cout << "The volume is :" << volume << endl;

return 0;
}
