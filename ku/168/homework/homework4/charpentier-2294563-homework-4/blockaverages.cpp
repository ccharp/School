/*  
 * blockaverages.cpp
 * Corbin Charpentier
 * EECS168
 * Homework .4
 * 11.18.2010
 * an explanation of what the code is supposed to do 
 */
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cmath>

using namespace std;

const int arraysize = 10;

double round(double x);

int main()
{
	ifstream infile; 
	ofstream outfile;
	string filename; //user designated file to open
	int avgrows, avgcols, sum = 0;

	//variables used to find and calculate block averages of array[][]
	double array[arraysize][arraysize], columns, number, avg, divisor;
	//outputs block averages of array[][]
	double outputarray[arraysize][arraysize];
	
	cout << "Enter the filename to read the table from: ";
	cin >> filename;//user designates desired for input
			//in this case, should be "num3.dat"

	//opens input file and checks to see if file exists.
	infile.open(filename.c_str());
	if(infile.fail())
	{
		cout << "Opening of " << filename << " failed.\n";
		exit(1);
	}

	//opens output file
	outfile.open("testing.txt");
	if(outfile.fail())
	{
		cout << "Outputfile opening failed.\n";
		exit(1);
	}
	
	//obtains number of columns from user designated file
	infile >> columns;
		
	//assignes numbers from .dat file to array	
	for(int i = 0; i < columns; i++)
	{	
		for(int j = 0; j < columns; j++)
		{
			infile >> number;
			array[i][j] = number;		
		}
	}
	
	outfile << "---The Original Table---" << endl;

	//outputs the original table
	for(int i = 0; i < columns; i++)
		{	
			for(int j = 0; j < columns; j++)
			{
				outfile << array[i][j] << " ";
				cout << array[i][j] << " ";
			}
			cout << endl;
			outfile << endl;
		}

	cout << "Enter the size for block averages," << endl
	     << "How many rows? (1 - " << columns << "): ";
	cin >> avgrows;
	cout <<"How many columns ( 1- " << columns << "): ";
	cin >> avgcols;	

	
	/*Obtains block averages. A 3x3 array for example, starting at coordinate 0,0, taking a user designated sized 	       *      square with 0,0 as the starting point. Once that average is compute, the program repeats the process 
	 *	for points 0,1, 0,2, 1,0 etc.
	 */
	for(int i = 0; i < avgrows; i++)
	{	
		for(int j = 0; j < avgcols; j++)
		{	
			for(int y = 0; y < avgrows; y++)
			{
				for(int x = 0; x < avgcols; x++)
				{	
					sum = sum + array[i + x][j + y];
				}
			}
			divisor = avgrows*avgcols; //calculates devisor for average
			avg = sum/divisor; //calculates average
			sum = 0; //sets sum to zero for next calculation
			outputarray[i][j] = round(avg); //function "round" rounds numbers to nears whole number. assignes 
		}					//	returned number to "outputarray[][]"
		
	}

	cout << "---Block Averages---\n";
	outfile << "---Block Averages---\n";

	//outputs block average
	for(int i = 0; i < avgrows; i++)
		{	
			for(int j = 0; j < avgcols; j++)
			{
				outfile << outputarray[i][j] << " ";
				cout << outputarray[i][j] << " ";
			}
			cout << endl;
			outfile << endl;
		}

 	return 0;
}

//rounds averages to nearest whole number
double round(double x) {
  return ((x - floor(x)) >= 0.5) ? ceil(x) : floor(x);
}



