#include <iostream>

using namespace std;

int main()


{
int x=4, y=2;
double quotient;
//sets precision to two decimal places
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(4);

quotient = x / y;

//output will be 2.0000
cout << quotient << endl;


return 0;
}
