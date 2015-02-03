//Programmer: Corbin Charpentier
//Date: 10/26/10
//
//Program writes data to an away from a file and outputs the array to another file 
//	called out.txt.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//reads and assigns numbers to array
void readarray(double[], double, int);

//outputs the arrays values to out.txt
void output(double[], int);

int main()
{	

	//variable declarations
	const int ARRAY_SIZE = 15;
	double array[ARRAY_SIZE]; //array
	int i = 0;
	
	//function calls
	readarray(array, ARRAY_SIZE, i);
	output(array, i);

	return 0;
}

//read array definition. assisngs numbers from input.txt to array[]
void readarray(double array[], double ARRAY_SIZE, int i)
{

	ifstream infile;
	infile.setf(ios::fixed);
	infile.setf(ios::showpoint);
	infile.precision(2);

	
	double number;
	
	//opening input.txt
	infile.open("input.txt");
	if(infile.fail())
	{
		cout << "Input document opening failed." << endl;
		exit(1);
	}

	//loop controls size of array and what number is assigned to each index
	for(i=0; i<15; i++)
	{
		infile >> number;
		array[i] = number;
	}
		
	infile.close();
}


void output(double array[], int i)
{
	ofstream outfile;
	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(2);	
	
	//opening out.txt
	outfile.open("out.text");
	if(outfile.fail())
	{
		cout << " Output document opening failed." <<endl;
		exit(1);	
	}
	
	//loop controls how many and what numbers are outputed to out.txt
	for(i=0; i<15; i++)
	{
		outfile << array[i] << " ";
	}
		
	outfile.close();
}	






























