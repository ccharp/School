// avg.cpp
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream number_file;
    number_file.open("numb.txt"); 
    
    if (number_file.fail())
    {
        cout << "Failed to open file." << endl;
        exit(1);
    }
    
    int input;
    int count = 0;
    double total = 0;
    
    while(number_file >> input)
    {
        count++;
        total += input;
    }
    
    number_file.close();
    
    cout << "The average of all numbers was " << total / count << endl;
    
    return 0;
}
