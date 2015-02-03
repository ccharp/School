//Corbin Charpentier

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	string firstname, lastname;
	char grade[5], number;
	
	infile.open("score.dat");
	if(infile.fail())
	{
		cout << "File opening failed.\n";
		exit(1);
	}

	outfile.open("OUTPUTFILE.txt");
	if(outfile.fail())
	{
		cout << "Outputfile opening failed.\n";
		exit(1);
	}
	
	outfile << "Student name             English	Math	Science Geography    History	GPA\n"
		<< "=============================================================================\n";

	infile >> firstname >> lastname;
	for(int i=0; i<5; i++)
	{
		infile >> number;
		if(number >= 90)
		{
			grade[i] = 'A';
		}
		else if(number >= 80)
		{
			grade[i] = 'B';
		}
		else if(number >= 70)
		{
			grade[i] = 'C';
		}
		else if(number >= 60)
		{
			grade[i] = 'D';
		}
		else
		{
			grade[i] = 'F':
		}

	}

	outfile << lastname << ", " << firstname;
	for(int i=0; i<5; i++)
	{
		outfile << grade[i] << "    ";
	}

	
	

	return 0;
}
	
	
