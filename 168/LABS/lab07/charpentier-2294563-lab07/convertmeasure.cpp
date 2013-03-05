/* 
 *  <Your convertmeasure.cpp filename>
 *
 *  Created by Corbin Charpentier
 *  Contact Email: corbin1@ku.edu
 *  Description: Converts inputed height and weight to either US System of Metric System
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  Date: 10/5/10
 *  
 * 
 */

#include <iostream>
using namespace std;

//function that gets input from user
void getmeasurements(float& height, float& weight);

//converts US to Metric
float converttoMetric(float& height, float& weight);

//converts Metric to US
float converttoUS(float& height, float& weight);

//outputs converstion to user
void result(float height, float weight);


int main()
{
  int choice=0; 
  float height=0.0, weight=0.0;
  do{  
     cout << "Welcome! This program converst user designated input to the different type (cm, inch, lbs, kg)\n"
          << "Which measure system would like to choose input (will convert to opposing unit): \n"
          << "1. United States Customary Units (inch)\n"
          << "2. International Metric Units (cm)\n";
     cin >> choice;
  }while(choice < 0 || choice > 3); //program will continue to run until 1 or 2 is entered
   
  //converst US Custumary unites to metric
  if(choice == 1)
  {
	getmeasurements(height, weight);//user input
	converttoMetric(height, weight);//converter function
  }

  //converst metric to US Customary
  if(choice == 2)
  {
	getmeasurements(height, weight);//user input
	converttoUS(height, weight);//converter function
  }

  
  result(height, weight);//outputs results
	
    
  return 0;
}

//function that gets input from user
void getmeasurements(float& height, float& weight)
{
	cout << "Please enter you height and weight separated by a space: ";
	cin >> height >> weight;
}

//converts US to Metric
float converttoMetric(float& height, float& weight)
{
	height = height * 2.54;
	weight = weight / 2.2;
	return(height, weight);
}

//converts Metric to US
float converttoUS(float& height, float& weight)
{
	height = height*.39;
	weight = weight * 2.2;
	return(height, weight);
}

//outputs converstion to user
void result(float height, float weight)
{
	cout<<"Your height converted is: "<< height << endl;
	cout<<"Your weight converted is: "<< weight << endl;
}















































