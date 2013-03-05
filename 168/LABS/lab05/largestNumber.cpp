//LargestNumber.cpp
//Program will tell you which of 5 numbers is greatest in value

#include <iostream>
using namespace std;

//function declaration. First two numbers are compared, then the larger of the two with the next number, and so on
double larger(double num1, double num2);

int main()
{       //variable declarations
        double number;
	double max;
	int count;
	

	//
	cout << "Enter 5 numbers." << endl;
	max = 0;
	
        // Control five number input. also calculates highest number 
	for (count=1; count<=5; count++)
	{
		cin >> number;
		max = larger(max, number);
	}
	//outputs the results of the function
	cout << "The largest number is " << max << endl;
	
	return 0;
}

//FUNCTION DEFINITION
double larger(double num1, double num2)
{
	if(num1 >= num2)
	{
		return (num1); //returns the first number		
	}
	else
	{
		return (num2); //returns the second number
	}
}

