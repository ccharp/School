#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std; 

int main()
{
	ifstream infile;
	ofstream outfile; 
	string infilename, outfilename;
	char array[50][20], next;
	int i=0, j=0;
	
	cout << "Please enter the file you wish to input from: ";
	cin >> infilename;
	cout << "Please enter the file you wish to output to: ";
	cin >> outfilename;

	infile.open(infilename.c_str());
	if(infile.fail())
	{
		cout << "Inputfile failed to open\n";
		exit(1);
	}
	
	outfile.open(outfilename.c_str());
	if(outfile.fail())
	{
		cout << "Output file failed to open\n";
		exit(1);
	}

	
		for(i=0; i<50; i++)
		{
			infile >> next;
			cout << next;
			if(isspace(next))
			{
			j++;
			}
			array[i][j] = next;
		}
	
	for(i=0; i<50; i++)
	{
		for(j=19; j>=0; j--)
		{	
			outfile << array[i][j];
		}
	}
		

			
	

	infile.close();
	outfile.close();
return 0;
}
