#include <iostream>
using namespace std;

int main()
{
    cout << "This program will compare the largest of three numbers." << endl;
    
  
    cout << "Enter the first number";
    double a;
    cin >> a;
    cout << "Enter the second number";
    double b;
    cin >> b;
	 cout<< "Enter the third number";
double c;	 
cin>>c;
 
    
 	 // determine which is larger
    if (a == b && b == c)
    
        cout << "All the numbers are equal" << endl;
    
    else if (a < b && b > c)
    
       cout << "The largest is b" << endl;
    
    else if (a > b && b > c)
    
        cout << "The largest is a" << endl;
    
    else
	 
	     cout<< "The largest is c" << endl;
	 	
    return 0;
}




