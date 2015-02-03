/*
 *  FinalGrade.cpp
 *
 *  Created by Thomas Peterman
 *  Contact Email: tpeteman@ku.edu
 *  Description: This program calculates an EECS168 student's average scores
 *                 from lab assignments, lab tests, homework assignments, and
 *                 the final project, and determines his final grade based on
 *                 grade scaling criteria. All of this is handled via file I/O.
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  Date: 11/1/2010
 *  Update: 11/1/2010
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Constant Declaration -- # of scores for each criterion.
const int labTimes = 14, examTimes = 4, hwTimes = 5, projTimes = 1;

// Function Declaration
void InitialScheme(ifstream& infile, int& labPercent, int& testPercent,
                   int& hwPercent, int& projPercent);
void GradesResult(ifstream& infile, ofstream& outfile, int labPercent,
                  int testPercent, int hwPercent, int projPercent);
void PrintName(ifstream& infile, ofstream& outfile);
double GetAverageInput(ifstream& infile, int numScores);

// Main function
int main()
{
	// Variable Declarations
	// File streams
	ifstream scheme, grades;
	ofstream results;
	// Grading scheme weights
	int labPercent, testPercent, hwPercent, projPercent;
	
	// Open files for I/O, and check for errors:
	// Grading Scheme
	cout << "Opening \"GradingSystem.txt\"... ";
	scheme.open("GradingSystem.txt");
	if ( scheme.fail() )
	{
		cout << "Failed to open." << endl;
		exit(1);
	}
	// User's grade data
	cout << endl << "        \"EECS168_score.txt\" ... ";
	grades.open("EECS168_score.txt");
	if ( grades.fail() )
	{
		cout << "Failed to open." << endl;
		exit(1);
	}
	// Final grade results
	cout << endl << "        \"EECS168_FinalGrade.txt\" ... ";
	results.open("EECS168_FinalGrade.txt");
	if ( results.fail() )
	{
		cout << "Failed to open." << endl;
		exit(1);
	}
	cout << "Done." << endl;

	// Function Invocation -- get the grading scheme, calculate
	//   and output the results.
	cout << "Setting grade scale criteria ... ";
	InitialScheme(scheme, labPercent, testPercent, hwPercent, projPercent);
	cout << "Done." << endl << "Computing grade results ... ";
	GradesResult(grades, results, labPercent, testPercent, hwPercent,
                     projPercent);
	cout << "Done!" << endl << "Closing files." << endl;

	// Close file streams
	scheme.close();
	grades.close();
	results.close();

	// Done.
	return 0;
}

/*
 * Function InitialScheme()
 *   PRECONDITION: infile has been declared and opened to the score criteria
 *                 data file.
 *   POSTCONDITION: labPercent, testPercent, hwPercent, and projPercent are all
 *                  set to the appropriate values from the data file stream.
 *                  infile is not closed.
 */
void InitialScheme(ifstream& infile, int& labPercent, int& testPercent,
                   int& hwPercent, int& projPercent)
{
	// This file always stores only 4 different criteria, so store the
	//   criteria directly in the call-by-reference arguments:
	//   ORDER: Lab work; Lab tests; Homework; Project
	infile >> labPercent >> testPercent >> hwPercent >> projPercent;
}

/*
 * Function GradesResult()
 *   PRECONDITION: infile has been declared and opened to the student score
 *                   data file.
 *                 outfile has been declared and opened to the final grade
 *                   report file.
 *                 labPercent, testPercent, hwPercent, and projPercent are all
 *                   assigned their appropriate values.
 *   POSTCONDITION: All calculations and other output are sent to outfile,
 *                    and formatted appropriately. infile and outfile are not
 *                    closed.
 */
void GradesResult(ifstream& infile, ofstream& outfile, int labPercent,
                  int testPercent, int hwPercent, int projPercent)
{
	double labAvg, testAvg, hwAvg, projAvg; // Four average scores.
	double finalGrade;                      // Final grade score.

	// Output formatting
	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(3);

	outfile << "******** EECS 168 Score Report ********" << endl;	

	// Loop: We need to be able to print out score reports for each student
	//       -- each student is delineated by a new line. Technically this
	//       is accounted for by the constants above, which determine the
	//       number of scores for each section.
	while ( !infile.eof() )
	{
		outfile << "---------------------------------------" << endl;
		// Start with the name:
		outfile << "Student Name: ";

		// Invoke helper function twice, to grab first and last name.
		PrintName(infile, outfile);
		outfile << ' ';
		PrintName(infile, outfile);
		outfile << endl;
		
		// Invoke a helper function to get the average score
		// for each part of the grade.
		labAvg = GetAverageInput(infile, labTimes);
		testAvg = GetAverageInput(infile, examTimes);
		hwAvg = GetAverageInput(infile, hwTimes);
		projAvg = GetAverageInput(infile, projTimes);
		// I'm aware that the provided input only has one project score
		//   -- this is more for the sake of completeness, as there is
		//   the *possibility* of more than one project score.
		
		// Calculate the final grade.
		finalGrade = ( ( labAvg * labPercent ) / 100 )
		             + ( ( testAvg * testPercent ) / 100 )
		             + ( ( hwAvg * hwPercent ) / 100 )
		             + ( ( projAvg * projPercent ) / 100 );

		// Output the results:
		outfile << "Lab Average: " << labAvg << endl
		        << "Test Average: " << testAvg << endl
		        << "HW Average: " << hwAvg << endl
		        << "Project: " << projAvg << endl
		        << "Final Score: " << finalGrade << endl;

		// Jump to next line. In case of extraneous data:
		infile.ignore(256, '\n');
	}

	// Final line of output, for formatting.
	outfile << "---------------------------------------" << endl;
}

/*
 * Function PrintName()
 *   PRECONDITION: infile has been declared and opened to the student score
 *                   data file.
 *                 outfile has been declared and opened to the final grade
 *                   report file.
 *                 infile is set to the correct position in the stream for
 *                   string input.
 *   POSTCONDITION: outfile is sent part of the student's name, delineated by
 *                    a space. Neither stream is closed.
 */
void PrintName(ifstream& infile, ofstream& outfile)
{
	char letter;
	
	// Loop until we find a space -- delimiting part of the name.
	infile.get(letter);
	while(!isspace(letter))
	{
		// We aren't working with strings just yet, output directly
		// to the output file.
		outfile.put(letter);
		infile.get(letter);
	}
}

/*
 * Function GetAverageInput()
 *   PRECONDITION: infile has been declared and opened to the student score
 *                   data file.
 *                 infile is set to the correct position in the stream for
 *                   score integer input.
 *   POSTCONDITION: return value is the average of numScores of the student's
 *                    scores retrieved from infile. infile is not closed.
 */
double GetAverageInput(ifstream& infile, int numScores)
{
	double scores(0); // Sum of all scores
	int input(0);     // Individual score

	for ( int i = 0; i < numScores; i++ )
	{
		infile >> input;
		scores += (double)input;
	}
	
	// Average = sum of scores divided by number of scores.
	return ( scores / numScores );
}

