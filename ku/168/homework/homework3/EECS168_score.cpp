#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Constant Variables Declaration
const int labTimes = 14, testTimes = 4, hwTimes = 5, projTimes = 1;

// Function Declaration
void InitialScheme(ifstream& infile, int& labPercent, int & testPercent, int& hwPercent, int& projPercent);
void GradeResult(ifstream& infile, ofstream& outfile, int labPercent, int testPercent, int hwPercent, int projPercent);

int main()
{
	// INSERT Your Code: Declaration of Variables and File Streams
	ifstream inscore, inscheme;
	ofstream outfile;
	int labScore, testScore, hwScore, proScore, number;

	// INSERT Your Code: Open Files for I/O
	inscore.open("scores.txt");
	if(inscore.fail())
	{
		cout << "File opeing failed.\n";
		exit(1);
	}

	inscheme.open("gradingsystem.txt");
	if(inscheme.fail())
	{
		cout << "File opeing failed.\n";
		exit(1);
	}

	outfile.open("OUTPUTFILE.txt");
	if(outfile.fail())
	{
		cout << "Outputfile opening failed.\n";
		exit(1);
	}

	

	// INSERT Your Code: Function Call (Function Invocation)
	InitialScheme();
	GradeResult(inscore, outfile, labScore, testScore, hwScore, proScore);
	return 0;
}
//-----------------------------------------------------------------------------------------------------
void InitialScheme(ifstream& inscheme, )
{
	cout << "good";			


	
		
}
//-----------------------------------------------------------------------------------------------------
void GradeResult(ifstream& ingrade, ofstream& outfile, int labPercent, int testPercent, int hwPercent, int projPercent)
{
        cout << "cool";
}




















