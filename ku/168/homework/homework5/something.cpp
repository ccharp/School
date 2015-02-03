#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

// CONSTANTS:
const int SIZE = 50;                 // Maximum size
const int CLASS_COUNT = 5;           // # of classes
const double CREDIT_HOURS = 3.0;     // Credit hours per class
const string INPUT = "score.dat";    // Input file
const string OUTPUT = "output.txt";  // Output file

void read_data( ifstream &fin, string names[], char grades[][CLASS_COUNT],
                int size, int &num_students );
char getLetterGrade( double score );
void compute_gpa( char grades[][CLASS_COUNT], double gpa[], int size );
void print_data( ofstream &fout, string names[], char grades[][CLASS_COUNT],
                 double gpa[], int size );

int main()
{
	ifstream fin;
	ofstream fout;
	string names[SIZE];
	char grades[SIZE][CLASS_COUNT];
	double gpa[SIZE];
	int num_students;

	// Open files for IO and check for errors.
	fin.open(INPUT.c_str());
	if ( fin.fail() )
	{
		cout << "Failed to open " << INPUT << ".\n";
		exit(1);
	}
	fout.open(OUTPUT.c_str());
	if ( fout.fail() )
	{
		cout << "Failed to open " << OUTPUT << ".\n";
		exit(1);
	}

	// Read data from the input file.
	read_data(fin, names, grades, SIZE, num_students);
	// Compute each student's GPA.
	compute_gpa(grades, gpa, num_students);
	// Output the results to the output file.
	print_data(fout, names, grades, gpa, num_students);

	// Close files.
	fin.close();
	fout.close();

	// Finished.
	return 0;
}

// Reads data from the specified input file.
void read_data( ifstream &fin, string names[], char grades[][CLASS_COUNT],
                int size, int &num_students )
{
	string first, last;
	double grade_input;

	// Loop through each line of the file
	num_students = 0;
	while ( !fin.eof() && num_students < size )
	{
		// Grab first name -- if the end of the file was already
		//   reached, break out of the loop!
		fin >> first;
		if ( fin.eof() ) break;

		// Grab last name, concatenate with first for future output.
		fin >> last;
		names[num_students] = last + ", " + first;

		// Loop through the students grades, and setup the letter grade
		//   matrix based on their scores.
		for ( int i = 0; i < CLASS_COUNT; i++ )
		{
			fin >> grade_input;
			grades[num_students][i] = getLetterGrade(grade_input);
		}

		// Jump to next line!
		num_students++;
		fin.ignore(1000, '\n');
	}
}

// Return a letter grade based on score (out of 100.0)
char getLetterGrade( double score )
{
	// Simple if/else if logic, return the appropriate letter grade
	// Based on a simple % scale.
	if ( score >= 90.0 ) return 'A';
	else if ( score >= 80.0 ) return 'B';
	else if ( score >= 70.0 ) return 'C';
	else if ( score >= 60.0 ) return 'D';
	return 'F';
}

// Compute a student's GPA based on letter grades.
void compute_gpa( char grades[][CLASS_COUNT], double gpa[], int size )
{
	int grade_points;

	// Loop through each student's letter grades:
	for ( int i = 0; i < size; i++ )
	{
		grade_points = 0;
		for ( int j = 0; j < CLASS_COUNT; j++ )
		{
			// Since every class is assumed to be a constant
			// # of credit hours, we can simply add up all grade
			// points:
			switch ( grades[i][j] )
			{
				case 'A': grade_points++;
				case 'B': grade_points++;
				case 'C': grade_points++;
				case 'D': grade_points++;
			}
		}

		// GPA calculation: grade points * credit hours,
		//   Divided by credit hours * # of classes.
		gpa[i] = ( grade_points * CREDIT_HOURS )
		         / ( CREDIT_HOURS * CLASS_COUNT);
	}
}

// Output all relevant data to the specified output file.
void print_data( ofstream &fout, string names[], char grades[][CLASS_COUNT],
                 double gpa[], int size )
{
	// Formatting...
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(1);

	// More formatting...
	fout << left << setw(30) << "Student Name" << setw(12) << "English"
	     << setw(12) << "Math" << setw(12) << "Science" << setw(12)
	     << "Geography" << setw(12) << "History" << setw(12) << "GPA\n";
	fout << "============================================================"
	     << "===========================\n";

	// Print the student's Last Name, First Name, letter grades, GPA.
	for ( int i = 0; i < size; i++ )
	{
		fout << left << setw(30) << names[i];
		for ( int j = 0; j < CLASS_COUNT; j++ )
		{
			fout << left << setw(12) << grades[i][j];
		}
		fout << left << setw(12) << gpa[i] << endl;
	}
}

