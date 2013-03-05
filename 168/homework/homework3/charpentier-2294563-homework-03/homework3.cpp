#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

// Constant Variables Declaration
const double labTimes = 14, testTimes = 4, hwTimes = 5, projTimes = 1;

//initialscheme gathers grade scale data
void InitialScheme(ifstream& infile, double& labPercent, double& testPercent, double& hwPercent, double& projPercent);

//GradeResult gathers date from scores.txt, finds averages, and outputs them along with the name to OUTPUTFILE.txt
void GradeResult(ifstream& infile, ofstream& outfile, double labPercent, double testPercent, double hwPercent, double projPercent);

int main()
{
	//variable declarations
	ifstream inscore, inscheme;
	ofstream outfile;
	double labScore, testScore, hwScore, proScore, number;
	

	//File openings and error messages
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

	

	//Function calls. 
	InitialScheme(inscheme, labScore, testScore, hwScore, proScore);
	GradeResult(inscore, outfile, labScore, testScore, hwScore, proScore);
	return 0;
}
//data is gathered from "gradingsystem.txt" and assigned to a variable
void InitialScheme(ifstream& infile, double& labPercent, double& testPercent, double& hwPercent, double& projPercent)
{
        double number;
	infile >> number;
	labPercent = number;	

	infile >> number;
	testPercent = number;	
	
	infile >> number;
	hwPercent = number;	

	infile >> number;
	projPercent = number;
	
}

//Void function gathers names and scores from scores.txt, calculates their average, and outputs the results to OUTPUTFILE.txt
void GradeResult(ifstream& infile, ofstream& outfile, double labPercent, double testPercent, double hwPercent, double projPercent)
{	// variable declarations
	double score; double sum = 0, labavg, testavg, hwavg, projavg, totalscore;
        string firstname, secondname;
	outfile << "********EECS 168 Score Report **********" << endl;

	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(3);	
	//while loop controls how many times the calculatiosn will done, once for each person. program ends when scores.txt does.
	while(! infile.eof()){
	infile >> firstname >> secondname; //string data type used to acquire names
	outfile << "-----------------------------------------" << endl;
	outfile << "Student Name: " << firstname << " " << secondname << endl;
	
	//first 14 scores are labs	
	for(int i=1; i <= 14; i++)
	{
		infile >> score; 
		sum = sum + score;
	}
	labavg = sum/14;
	
	sum = 0; //resets sum to 0
	for(int i=1; i <= 4; i++) //scores 15-18 are tests
	{
		infile >> score;
		sum = sum + score;
	}
	testavg = sum/4;

	sum = 0; //resets sum to 0
	for(int i=1; i <= 5; i++)//scores 19-23 are homework
	{
		infile >> score; 
		sum = sum + score;
	}
	hwavg = sum/5;

	infile >> score;  // the final score is a lab
	projavg =score;
	
	//calculation for total score using averages
	totalscore = labavg*(labPercent/100)+testavg*(testPercent/100)+hwavg*(hwPercent/100)+projavg*(projPercent/100);
	
	//outputs averages
	outfile << "Lab Average: " << labavg << endl
		<< "Test Average: " << testavg << endl
		<< "Homework Average: " << hwavg << endl
		<< "Project Score: " << projavg << endl
		<< "Total Score: " << totalscore << endl;

	//resets all values to 0 for next calculation
	sum = 0; labavg = 0; testavg = 0; hwavg = 0; projavg = 0; totalscore = 0;

	}
		
}













