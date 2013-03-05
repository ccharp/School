/*
 *  clothing.cpp 
 *
 *  Created by Corbin Charpentier
 *  Contact Email: corbin1@ku.edu
 *  Description: <write out what the program does>
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  Date: <The original date you created the program>
 *  Update: 10/10/10
 * 
 */

#include <iostream>
using namespace std;


//calculates clothing size, and waist size
void clothing_size(double height, double weight, int age);


int main()
{

	//variable declations
	double height, weight, age, exit;

	cout << "============================================="<<endl
	     << "                  Welcome!"                   <<endl
 	     << "This program will compute your clothing size."<<endl
	     << "============================================="<<endl;	


	//loop ends when user inputs 0
	do{

		//input gathering
		cout << "Please input your height in inches: ";
		cin  >> height;

		cout << "Please input your weight in pounds: ";
		cin  >> weight;
		
		cout << "Please enter your age: ";
		cin  >> age;
		cout << endl;
	
		//FUNCTION CALL clothing size
		clothing_size(height, weight, age);



		cout << "Do you want another try?" << endl
	     	<< "Press 1 for another try." << endl
	    	<< "Press 0 to exit." << endl;
		cin  >> exit;
		cout << endl;

	}while(exit != 0);

	return 0; 
}



//FUNCTION DEFINITION
void clothing_size(double height, double weight, int age)
{
	double hat_size, jacket_size, waist_size;
	
	hat_size = weight/height*2.9;
	
	//if age is greater than 39, additional length difference of age and 30, divided by 10, times one eigth
	if(age <= 39)
	{
		jacket_size = height*weight/288;
	}
	else
	{
		jacket_size = (height*weight/288 + ((age - 30)/10*.135));
	}

	//if age is greater than 28, additional size is difference if age and 28, divided by 2, times one tenth
	if(age <= 28)
	{
		waist_size = weight/5.7;
	}
	else
	{
		waist_size = (weight/5.7 + (age - 28)/2*.1);
	}

	
	//sets decimal places to a maximum of two places after zero
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);		


	//hat, jacket, and waist size output
	cout << "Your hat size is " << hat_size << endl;
	cout << "Your jacket size is " <<jacket_size << endl;
	cout << "Your waist size is " <<waist_size << endl << endl;

	
	
}






























	

