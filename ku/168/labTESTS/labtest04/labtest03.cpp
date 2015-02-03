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
	char grade[6];
	double number, GPA, sum(0);
	
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
	
	outfile << "Student name             English        Math	   Science     Geography    History     GPA\n"
		<< "=================================================================================================\n";

while(infile >> firstname){

	
	infile >> lastname;
	for(int i=0; i<5; i++)
	{
		infile >> number;
		
		if(number >= 90)
		{
			grade[i] = 'A';
			sum = sum + 4;
		}
		else if(number >= 80)
		{
			grade[i] = 'B';
			sum = sum + 3;
		}
		else if(number >= 70)
		{
			grade[i] = 'C';
			sum = sum + 2;
		}
		else if(number >= 60)
		{
			grade[i] = 'D';
			sum = sum + 1;
		}
		else
		{
			grade[i] = 'F';
		}
		cout << grade[i];
	}
		GPA = sum/5;		

	outfile << setw(15) << lastname << ", " << firstname;
	for(int i=0; i<5; i++)
	{
		outfile << setw(12) << grade[i] << setw(12) ;
	}
	outfile << GPA;
	sum = 0;
	GPA = 0;
	outfile << endl;	
}
	

	return 0;
}
	
	
