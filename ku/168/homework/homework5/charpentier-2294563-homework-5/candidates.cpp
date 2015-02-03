/*  
 * Program: candidates.cpp
 * Programmer: Corbin Charpentier
 * Class: EECS168
 * Assignment: Homework 5
 * Date: 11.7.2010
 * Desctiption: Program let's user designate amout of data to entered. Program stores names and votes in
 *	        arrays 'name' and 'votes'. Program decides who winner is based on number of votes.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{

	//variable declarations. 
	//NOTE: pointer variables are declared later
	ofstream outfile;
	int array_size;
	double next, winner_votes(0), sum(0), percent;
	string candidate, winner_name;

	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(2);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//opens output file
	outfile.open("results.txt");
	if(outfile.fail())
	{
		cout << "Opening failed" << endl;
		exit(1);
	}
	
	cout << "Please enter the number of candidates: ";
	cin >> array_size;
	cout << "Enter candidate's name and the votes received by the candidate: ";
	
	//points and dynamic arrays initialized 
	string *name;
	name = new string[array_size]; //holds names
	int *votes;
	votes = new int[array_size]; //holds votes

	//Assigns value to arrays. Names are assigned votes based on index.
	//  This section also calculates the sum of votes and winner.
	for(int i=0; i < array_size; i++)	
	{
		cin >> candidate;
		name[i] = candidate;
		
		cin >> next;
		votes[i] = next;

		sum = sum + next;

		if(next > winner_votes)
		{
			winner_votes = next;
			winner_name = candidate;
		}
	}
	
	cout << "Candidate    Votes Recieved   % of Total Votes" << endl
	     << "===============================================" << endl; 
	outfile << "Candidate    Votes Recieved   % of Total Votes" << endl
	        << "===============================================" << endl;  
 
	//outputs arrays to outfile and calculates the percent of votes	
	for(int i=0; i < array_size; i++)
	{
		percent = votes[i]/sum*100;
		cout << name[i] << setw(20) << votes[i] << setw(20) << percent << endl;
		outfile << name[i] << setw(20) << votes[i] << setw(20) << percent << endl;
	}
	cout << "===============================================" << endl;
	outfile << "===============================================" << endl;
	//outputs winner to outfile.
	cout << " * " << winner_name << " had the most votes with " << winner_votes << " and won the election.\n";
	
	outfile << " * " << winner_name << " had the most votes with " << winner_votes << " and won the election.\n";
	return 0;
}


