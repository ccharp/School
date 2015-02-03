#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

#include "Pipeline.hpp"

using namespace std;

int main() { 
	string infile;
	string timingfile;
	string regfile;

	int mode;

	cout << "Enter to read from: ";
	cin >> infile; cout << endl;	

	bool valid_mode = false;
	while(!valid_mode) {
		cout << "Enter '0' for no bypassing\n";
		cout << "      '1' for bypassing-branch-taken\n";
		cout << "      '2' for bypassing-branch-not-taken: ";

		cin >> mode; cout << endl;
		if(mode < 3) {
			valid_mode = true;
		} else {
			cout << "Mode: " << mode << " is an invalid mode. Try again.\n";
		}
	}

	cout << "Enter file to write timing to: ";
	cin >> timingfile; cout << endl;

	cout << "Enter file to write registers' contents to: ";
	cin >> regfile; cout << endl;

	Pipeline *pipeline = new Pipeline(
		infile, 
		timingfile, 
		regfile,
		(WHICH_TIMING)mode	
	);

	pipeline->getInput();
	pipeline->executeProgram();
	pipeline->printRegisters();

	pipeline->printTimings();

	return 0;
}




