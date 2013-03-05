#include <iostream>
using namespace std;
int main ()

{

char operation;
double firstnumber, secondnumber, sum, difference, product, quotient;


do
{

//user input and directions
cout << "Enter # key at operator input to terminate program. To use this program, please enter a number, then press enter, then an operation (+,-,*,/), enter again, and then the last number. \n";
cout << "Please enter the first number: \n";
cin  >> firstnumber;
cout << "Please enter an operator: \n";
cin  >> operation;
cout << "Please enter the second number: \n";
cin  >> secondnumber;


//switch operation

switch (operation)
{
		case '+': //for addition
			sum = firstnumber + secondnumber;
			cout << "The sum is: " << sum << endl;
			break;
		case '-': //for subtraction
			difference = firstnumber - secondnumber;
			cout << "the difference is: " << difference <<endl;
			break;
		case '*': //for multiplication
			product = firstnumber*secondnumber;
			cout << "The product is: " << product <<endl;
			break;
		case '/': //for division
						
			quotient = firstnumber / secondnumber;
			cout << "the quotient is: " << quotient << endl;
			break;
		case '#':
			cout << "terminate program\n";
			return 0;
		default: 
			cout << "SYNTAX ERROR. Number or operation are not valid. Please try again.\n";
}

}  while (operation != '#');


return 0;

}
			
				
