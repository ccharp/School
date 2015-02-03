/*
 *  <factorial.cpp>
 *
 *  Created by Corbin Charpentier
 *  Contact Email: corbin1@ku.edu
 *  Description: calculates factorial of positive integer>
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  Date: 9/7/2010
 *  Update: 
 * 
 */

// Prompt out notice for the user to input a positive integer.
// Use while loop to handle the calculation of the input integer's factorial.
// Print out the result to screen for the user.

#include <iostream>
using namespace std;

int main()
{
int positive_integer;
  cout << "please input a positive integer:" << endl;
  cin >> positive_integer; 
	int count=1;
	int factorial=1;
		
	while (count <= positive_integer)
	{
  	  factorial = factorial * count;
	  cout << "count :" << count << endl;
	  count = count + 1;
	}


  //Result
  cout << "The factorial of your input integer is: " << factorial << endl;
  
  return 0;
}

