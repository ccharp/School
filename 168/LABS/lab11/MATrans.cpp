// Your Source Code Header
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_COL = 50;
const int MAX_ROW = 50;
int i, j;

//fills array
void file22DArray(ifstream& inFile, int mat[][MAX_COL], int row, int col);

//transposes array
void transpose(int mat[][MAX_COL], int row, int col);

//outputs transposed array
void output2DArray(ofstream& outFile, int mat[][MAX_COL], int row, int col);

int main()
{   //variable declarations
    ifstream fin;
    ofstream fout;
    int row(5), col(5);
    int mat[MAX_ROW][MAX_COL];

	//if opening fails: "Fail to open the input file"
    fin.open("inFile.dat");
    if(fin.fail())
    {
        cout << "Fail to Open the Input File.\n";
        exit(1);
    }
    
	//if output file opening fails: "Fail to open the outfil File."
    fout.open("outFile.dat");
    if(fout.fail())
    {
        cout << "Fail to Open the Output File.\n";
        exit(1);
    }
    
    // INSERT YOUR CODE: Function Call
    file22DArray(fin, mat, row, col);
    transpose(mat, row, col);
    output2DArray(fout, mat, row, col);

    fin.close();
    fout.close();
    
    return 0;
}

//function that fills the array
void file22DArray(ifstream& inFile, int mat[][MAX_COL], int row, int col)
{
	int number;
	for(i=0; i < row; i++)
	{
	
		for(j=0; j < col; j++)
		{
			inFile >> number;
			mat[i][j] = number;
		}
	}
		
}


//function that transposes the numbers of the array
void transpose(int mat[][MAX_COL], int row, int col)
{
	int number, temp;
	for(i=0; i < row; i++)
	{
		for(j=0; j < col; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}

//function that outputs the transposed array
void output2DArray(ofstream& outFile, int mat[][MAX_COL], int row, int col)
{
	for(int i=0;i < row ; i++)
        {
        	for(int j=0;j < col ; j++){
            	outFile << mat[j][i] << " ";
        }
        outFile << endl;
    }
}



































