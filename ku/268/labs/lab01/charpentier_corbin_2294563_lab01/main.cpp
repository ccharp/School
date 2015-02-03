#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std; 

int main()
{
	ifstream infile;
	ofstream outfile; 
	string infilename, outfilename, line;
	int characters;
	
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

	while(getline(infile, line))
	{
		characters = line.length();
		cout << line << endl;
		for(int i=characters-1; i>=0; i--)
		{
			outfile << line[i];
		}
		outfile << endl;		
	}

	infile.close();
	outfile.close();
return 0;
}
