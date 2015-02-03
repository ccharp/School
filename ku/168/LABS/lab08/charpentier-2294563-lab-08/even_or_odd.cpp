//even_or_odd.cpp
//Corbin Charpentier
//
//Program reads a file and outputs number of even and odds. 

#include <iostream>
#include <fstream> 
#include <cstdlib>

using namespace std;

int main()
{	

	//function declarations
	int input, even_count(0), odd_count(0), total_even, total_odd;

	ifstream infile;
	ofstream outfile;

	//opens data file
	infile.open("numbers.dat");
	if (infile.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	//creates file to store data
	outfile.open("even_or_odd.txt");
	if (infile.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	

	//program runs until all numbers from numbers.dat are inputted 
	while (infile >> input)
	{
		if (input % 2 == 0)
		{
			outfile << "1 ";
			even_count++;
		}
		if (input % 2 != 0)
		{
			outfile << "0 ";
			odd_count++;
		} 
	}

	//calculates total of even and odd numbers
	total_even = even_count;
	total_odd = odd_count;
	

	//program out put
	cout << "There are " << total_even << " even numbers.\n";
	cout << "There are " << total_odd << " odd numbers.\n";

	infile.close();
	outfile.close();

return 0;
}
	
	




















































































