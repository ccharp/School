// I DON'T UNDERSTAND WHAT THIS PROGRAM IS SUPPOSED TO DO



//*************************************************************
// Author: Corbin Charpentier
//
// Program: Classify_Numbers.cpp
// This program reads N numbers and outputs the number of 
// zeros, odd, and even numbers.
//*************************************************************
 
#include <iostream>
using namespace std;  

//Function prototypes
void initialize(int& zeroCount, int& oddCount, int& evenCount);
void getNumber(int& num);
void classifyNumber(int num, int& zeroCount, int& oddCount, int& evenCount);
void printResults(int zeroCount, int oddCount, int evenCount);

int main ()
{
    //Variable declaration
    int N=0, counter; //loop control variable 
    int number;  //variable to store the new number 
    int zeros;   //variable to store the number of zeros 
    int odds;    //variable to store the number of odd integers 
    int evens;   //variable to store the number of even integers 

    initialize(zeros, odds, evens);                 //Function call for initialization

    cout << "Please enter the number of integers you would like to test: ";
    cin >> N; 

    for (counter = 1; counter <= N; counter++)      //Read N numbers
    {
        getNumber(N);                        //Function call
        cout << number << ", ";                      //print out the numbers
        
        //Function call for classifying numbers
        classifyNumber(number, zeros, odds, evens); 

    }   // end for loop 

    cout << endl;

    printResults(zeros, odds, evens);               //Print the final results.

    return 0;
}

//Initialization(example: zeroCount=0) 
void initialize(int& zeroCount, int& oddCount, int& evenCount)
{
	zeroCount=0;
	oddCount=0;
	evenCount=0;
}

//Read a number and then passes this number to the function 'main'.
void getNumber(int& num)
{
    cout << "Please enter an integer: ";
    cin >> num;
}

//To determine whether the number is odd or even, 
//and, if the number is even, it also checks whether the number is zero.
//Count evens, odds, and zeros.
void classifyNumber(int num, int& zeroCount, int& oddCount, int& evenCount)
{
	if (num =! 0 && num % 2 == 0)
	{
		num = evenCount;
	}
	else if ((num =! 0) && (num % 2 == 1))
	{
		num = oddCount;
	}
	else
	{
		num = zeroCount;
	}		
     
} //end classifyNumber


//Print the final results
void printResults(int zeroCount, int oddCount, int evenCount)
{ 
    cout << "There are " << evenCount << " evens, "
         << "which includes " << zeroCount << " zeros"
         << endl;

    cout << "The number of odd numbers is: " << oddCount
         << endl;
} //end printResults

