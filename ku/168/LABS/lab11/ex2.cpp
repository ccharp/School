/* ex2.cpp */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Specify the capacity of the two dimensional array.
const int MAX_COL = 10; 
const int MAX_ROW = 10;

// Function Declaration
void file22DArray(ifstream& inFile, int mat[][MAX_COL], int row, int col);
void output2DArray(ofstream& outFile, int mat[][MAX_COL], int row, int col);

int main(){
    // Variable Declaration
    ifstream fin;
    ofstream fout;
    int row(5), col(5);

    // INSERT YOUR CODE: Declare an int-typed two dimensional array using MAX_ROW and MAX_COL
    int array[MAX_ROW][MAX_COL];

    // Check the status of the file
    fin.open("inFile.dat");
    if(fin.fail()){
        cout << "Fail to Open the Input File.\n";
        exit(1);
    }
    
    fout.open("out.txt");
    if(fout.fail())
    {
        cout << "Fail to Open the output File.\n";
        exit(1);
    }

    file22DArray(fin, array, row, col);
    output2DArray(fout, array, row, col);   


    fin.close();
    fout.close();
}

void file22DArray(ifstream& inFile, int mat[][MAX_COL], int row, int col){
    int number;
    for(int i=0;i < row ; i++)
    { 
        for(int j=0 ;j < col ; j++){
            // INSERT YOUR CODE: Initialize the two dimensioanl array mat via reading file. 		
		
		inFile >> number;
		mat[i][j] = number;
		
		
        }
    } 
}

void output2DArray(ofstream& outFile, int mat[][MAX_COL], int row, int col){
    int number;
    for(int i=0;i < row ; i++)
    {
        for(int j=0;j < col ; j++){
            outFile << mat[i][j] << " ";
        }
        outFile << endl;
    }
}

