#include <iostream>
#include <fstream>          // You need this to work with files
using namespace std;

int main()
{
    ofstream outfile;     // create a file variable
    
    outfile.open("writefile.txt");

    // INSERT Your Code to output the following sentence to the file. 

	outfile << "Fall break is coming! Cheers.";
    // "Fall break is coming! Cheers."
    
    outfile.close();

    return 0;
}
