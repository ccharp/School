#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

// Constant Variables Declaration
const int labTimes = 14, testTimes = 4, homeworkTimes = 5, projTimes = 1;

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
	inscore.open("score.dat");
	if(inscore.fail())
	{
		cout << "File opeing failed..\n";
		exit(1);
	}

	inscheme.open("gradingsystem.dat");
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

	//closing files
	inscore.close();
	inscheme.close();
	outfile.close();
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

//Void function gathers names and scores from scores.txt, calculates 
//	their average, and outputs the results to OUTPUTFILE.txt
void GradeResult(ifstream& infile, ofstream& outfile, double labPercent, double testPercent, double hwPercent, double projPercent)
{	// variable declarations
	double score; double sum = 0, labavg, testavg, hwavg, projavg, totalscore;
	int number_of_students;
        string firstname, secondname;
	outfile << "********EECS 168 Score Report **********" << endl;

	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(3);	

	infile >> number_of_students;

	//while loop controls how many times the calculatiosn will done, once 
	//	for each person. program ends when scores.txt does.
	int count=1;
	while(count <= number_of_students){
	infile >> firstname >> secondname; //string data type used to acquire names
	outfile << "-----------------------------------------" << endl;
	outfile << "Student Name: " << firstname << " " << secondname << endl;
		
		cout << "hello";

		int *dArray;
		dArray = new int[24];
		for(int i=0; i < 24; i++)
		{
			infile >> score;
			dArray[i] = score;
		}
		
		//first 14 scores are labs	
		for(int i=1; i <= labTimes; i++)
		{ 
			sum = sum + dArray[i];
		}
		labavg = sum/labTimes;
	
		sum = 0; //resets sum to 0
		for(int i=1; i <= testTimes; i++) //scores 15-18 are tests
		{
			sum = sum + dArray[i];
		}
		testavg = sum/testTimes;

		sum = 0; //resets sum to 0
		for(int i=1; i <= homeworkTimes; i++)//scores 19-23 are homework
		{ 
			sum = sum + dArray[i];
		}
		hwavg = sum/homeworkTimes;

		// the final score is a lab
		projavg = dArray[24-1];
	
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
	count++;
	}
		
}
