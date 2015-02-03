#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
    //Declare variables
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable
	int next;

	inFile.open("messydata.dat");
	if(inFile.fail())
	{
		cout << "Opening failed" << endl;
		exit(1);
	}
	
	outFile.open("neat.txt");
	if(outFile.fail())
	{
		cout << "Opening failed" << endl;
		exit(1);
	}

	outFile.setf(ios::fixed);
	outFile.setf(ios::showpoint);
	outFile.precision(3);

	while(inFile >> next)
	{

		get.next(
		outFile << "1" << setw(15) << right << next << endl
			<< "2" << setw(15) << right << next << endl
			<< "3" << setw(15) << right << next << endl;
	}
		



	inFile.close();                              
        outFile.close();                                

        return 0;
 }
