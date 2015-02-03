#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std; 

int main()
{
	ifstream fin;
	string filename, word;
	int count = 0;
	

	cout << "Please input the name of the file you want to open: ";

	cin >> filename;

	fin.open(filename.c_str());
	if(fin.fail())
	{
    		cout << "Error: Fail to Open the File.\n";
    		exit(1);
	}
	while(fin >> word)
	{
		fin >> word;
		count++;
	}
	cout << "There are " << count << " words" <<endl;		

	return 0;
}
