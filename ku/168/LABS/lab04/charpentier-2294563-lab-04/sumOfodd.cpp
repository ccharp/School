/*
 *  sumOfodd.cpp
 *
 *  Created by Corbin Charpentier
 *  Contact Email: corbin1@ku.edu
 *  Description: <calculates sum of odd integers>
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  Date: <The original date you created the program>
 *  Update: <The date of your last edition of the program>
 * 
 */

#include <iostream>
using namespace std;

int main()
{
  int n, k, sum, count; 
  
  cout << "Welcome! This program calculates the summation of consecutive odd integers.\n"
       << "Please input a positive integer as the limit: ";
  cin >> n;
  
  sum = 0;
  //count = 1;
  k = 0;
  for (int count=1; count <= n; count = count+2)
	{
	//calculates sum of odd integers
	sum = sum + count;
	}

  
	//outputs result of calculation of odd integers
	 cout << "The summation is: " << sum << endl;
	

    
  

  
  return 0;


}
