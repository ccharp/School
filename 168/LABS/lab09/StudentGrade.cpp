// StudentGrade.cpp
//Program to calculate the average test score.
// Given a student's name and five test scores, this program
// calculates the average test score. The student's name, the
// five test scores, and the average test score is stored in 
// the file 'results.txt'. The data is input from the file 'test.dat'.
//************************************************************
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void processing(ifstream& inFile, ofstream& outFile);

int main()
{
    //Declare variables
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable
    
	inFile.open("test.dat");
	if(inFile.fail())
	{
		cout << "Opening failed" << endl;
		exit(1);
	}
	
	outFile.open("result.txt");
	if(outFile.fail())
	{
		cout << "Opening failed" << endl;
		exit(1);
	}
  
        //Function call
        processing(inFile, outFile);

        inFile.close();                              
        outFile.close();                                

        return 0;
 }

void processing(ifstream& inFile, ofstream& outFile)
{	//variable declarations 
	char letter;
	double number, avg, sum(0);


	//sets precision and decimal place
	outFile.setf(ios::fixed);
	outFile.setf(ios::showpoint);
	outFile.precision(2);
	

	
	outFile << "********************************************" << endl
		<< "Student Name: ";

	
	//outputs name to result.txt
	while(letter != '\n')
	{
		inFile.get(letter);
		outFile.put(letter);
	}

	outFile << "Test Scores: ";


	//outputs scores and finds their sum
	inFile >> number;
	while(! inFile.eof( ))
	{
		
		sum += number;
		outFile << number << setw(8);
		inFile >> number;
		
	}

	//calculates average
	avg = sum / 5.0;
	outFile << endl << "Average Score: " << avg << endl
		<< "********************************************" << endl;
	
     
}






































