//      Program name: review.cpp
//	Author: Corbin Charpentier      ID: 2294563
//	Date written: 9/29/2010
//	Program Description: Program tells user whether input number is even of odd


#include <iostream>
using namespace std;


//function declaration
void odd(int a);
void even(int a);


int main()
{

	int a=1;
	cout <<"Type a number (0 to exit): ";
	cin >>a;

    //while statement is not executed if user input is "0".
    while(a!=0)
    {
          
          odd(a); //function call

    }
    return 0;
}


//void "odd" definition
void odd(int a)
{
    if(a%2 != 0)
         cout <<"Number is odd \n";
    else
         even(a); //even function call
}

//void "even" devinition
void even(int a)
{

    if(a%2 == 0)
         cout <<"Number is even \n";
    else 
         odd(a); //odd function call
}



