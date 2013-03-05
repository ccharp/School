//Name: Corbin Charpentier
//Student ID: 2294563

#include <iostream>
using namespace std;

int operation(int, int);
double operation(double, double);

int main()
{
	int intnumber1, intnumber2, intresult;
	double doublenumber1, doublenumber2, doubleresult;
	char choice;
	
	cout << "Enter ""i"" for dinteger or ""d"" for double: ";
	cin >> choice;

	switch(choice)
	{
		case 'i':
		case 'I': 
			cout << "Please enter first and second number: ";
			cin  >> intnumber1 >> intnumber2;
			intresult = operation(intnumber1, intnumber2);
			cout << "The answer is: " << intresult;
			break;

		case 'd':
		case 'D': 
			cout << "Please enter first and second number: ";
			cin  >> doublenumber1 >> doublenumber2;
			doubleresult = operation(doublenumber1, doublenumber2);
			cout << "The answer is: " << doubleresult;
			break;
			
		default:
			cout << "invalid input";
			break;
	}
return 0;
}

int operation(int intnumber1, int intnumber2)
{
	
	char operation;

	cout << "Please enter ""+"" for addition or ""-"" for subraction: ";
	cin >> operation;

	switch(operation)
	{
		case '+':
			return(intnumber1 + intnumber1);
			break;
			
		case '-':
			return(intnumber1 - intnumber2);
			break;
		
		default:
			cout << "invalid input";
			break;
	}
}

double operation(double doublenumber1, double doublenumber2)
{
	
	char operation;

	cout << "Please enter ""+"" for addition or ""-"" for subraction: ";
	cin >> operation;

	switch(operation)
	{
		case '+':
			return(doublenumber1 + doublenumber1);
			break;
			
		case '-':
			return(doublenumber1 - doublenumber2);
			break;
		
		default:
			cout << "invalid input";
			break;
	}
}












































			
