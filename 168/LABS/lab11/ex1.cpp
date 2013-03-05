/* ex1.cpp */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;  // The Capacity of Array

// FUNCTION DECLARATION
void file2Array(ifstream& fin, double dArray[], int& arrSize, int arrCapacity);
double max(const double dArray[], int arrSize);
double min(const double dArray[], int arrSize);
double avg(const double dArray[], int arrSize);

int main(){
        // Variable Declaration
	ifstream fin;
	double dArray[MAX_SIZE];
	int arrSize = 0;

        // Open File and Check the File Status
	fin.open("num.txt");

	if(fin.fail()){
		cout << "Fail to Open the Input File.\n";
		exit(1);
	}
	
        // FUNCTION CALL
	file2Array(fin,dArray,arrSize,MAX_SIZE);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(2);
	cout	<< "The maximum number is " << max(dArray, arrSize)
		<< "\nThe minimum number is " << min(dArray, arrSize)
		<< "\nThe average is " << avg(dArray, arrSize) << endl;
	
	fin.close();
}

// FUNCTION DEFINITION
void file2Array(ifstream& fin, double dArray[], int& arrSize, int arrCapacity){
	arrSize = 15;
	double number;
	for(int i=0; i < arrSize; i++)
	{
		fin >> number;
		dArray[i] = number;
		
	}
		
}

double max(const double dArray[], int arrSize){
	double max_num = dArray[0];
	for(int i=0; i < arrSize; i++){
		if(dArray[i] > max_num)
			max_num = dArray[i];
	}
	return max_num;
}

double min(const double dArray[], int arrSize){
	double min_num = dArray[0];
	for(int i=0; i < arrSize; i++)
	{
		if(min_num < dArray[i])
			min_num = dArray[i];
	}
	return min_num;
}

double avg(const double dArray[], int arrSize){
	double sum = 0;	
	for(int i=0; i<arrSize; i++)
	{
		sum = sum + dArray[i];
	}
	return(sum/arrSize);
		
}




















