//File Name: example2.cpp
//Author: Luke Huan
///Email address: jhuan@ku.edu
//Example Number: 2
//Description: handling student information with class
//Last Changed: Jan 27, 2011

#include <iostream>
#include <stdlib.h>
#include "MyList.h"
using namespace std;

int main()
{
	MyList list;
	list.push_back(3);
	list.push_back(2);
	list.push_back(10);
	list.push_back(5);
	list.push_back(4);

	cout << "Note: The program did not specify means of input. As such, the program makes a list of 5 integers"
		 << " as seen above this line in the code and sorts them.\n" << endl;
	cout << "Before sort: " << list.toString();
	
	cout << endl;

	list.sort();

	cout << "After Sort: "<< list.toString() << endl; 
 	
  	return 0;
} 

