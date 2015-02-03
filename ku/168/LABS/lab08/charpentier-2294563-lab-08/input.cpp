#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream my_file; 
    int n1, n2, n3;

    cout << "Opening file \"infile.dat\"..." << endl;
    
    my_file.open("infile.dat");
    
    // this comment is a place-holder
    if (my_file.fail())
    {
    cout << "Failed to open file." << endl;
    exit(1);
    }

    
    // INSERT YOUR CODE: Read three numbers into n1, n2, and n3 respectly.
	my_file >> n1 >> n2 >> n3;    


    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    cout << "n3: " << n3 << endl;
    cout << "average of n1, n2, and n3: " << (n1 + n2 + n3) / 3.0 << endl;
    
    my_file.close();
    return 0;
}

