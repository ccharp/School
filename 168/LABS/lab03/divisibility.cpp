/* Checks if numbers are divisible by 3 and 9 */
#include <iostream>
using namespace std;

int main() // PROGRAM DOES NOT WORK. LOGIC ERROR.
{
   	//variable declaration

	int positive_integer;
	int sum=0;
	int diviser=10;
	bool divisibility_by_3 = (sum % 3 == 0);
	bool divisibility_by_9 = (sum % 9 == 0);

	//Input

	cout << "Please enter a positive integer: ";
	cin >> positive_integer;

  	//Determine that the sum of the digits is divisible by 3 and 9
	
	
	while (positive_integer <= 0)
	{
	positive_integer = positive_integer%10;
	sum = sum + positive_integer;
	positive_integer = positive_integer/10;
	}	

	//Use if..else statement.

        if (divisibility_by_3 == true && divisibility_by_9 == true)
   	{
	cout << "--result--" << endl;
	cout << "The sume of the digits is: "<< sum << endl;
	cout << positive_integer << " is divisible by 3" << endl;
	cout << positive_integer << " is divisible by 9" << endl;
	}
	
	else 
	{
	cout << "the number is not divisibile by 3 and 9." << endl;
	}

   return 0;
}

