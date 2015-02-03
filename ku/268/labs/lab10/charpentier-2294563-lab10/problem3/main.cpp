#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void pixel(int m, int n, char letter, char array[][100]);

void printArray(char array[][100], int m, int n);

int main(int argc, char* argv[])
{
	if(argc < 3)
        {
            cout << "hw1 inputFile" << endl; 
            exit(0);
        }
    string input = argv[1];
	string output = argv[2];
	ifstream fin(input.c_str());
	if(fin.fail()){
		cout << "intput failed to open" << endl;
		exit(1);}
	ofstream fout(output.c_str());
	if(fin.fail()){
		cout << "output failed to open" << endl;
		exit(1);}
		
	int m, n;
	char letter;
	
	fin >> m >> n;
	char array[m][100];
	//fill array
	int i,j;
	for(i=0; i<m; i++)
	{	
		for(j=0; j<n; j++)
		{
			fin >> letter;
			array[i][j] = letter;
		}
	}	
	printArray(array, m ,n);

	//get index to convert and letter
	fin >> m >> n >> letter;

	//call conversion function
	pixel(m, n, letter, array);
	
	printArray(array, m ,n);
	return 0;
}

//converts x to designated latter and checks adjacent letters
void pixel(int m, int n, char letter, char array[][100])
{
	if(array[m][n] == 'x')
	{
		//cout << "here" << endl;
		array[m][n] = letter;	
		
		pixel(m, n+1, letter, array);
		pixel(m-1, n, letter, array);
		pixel(m-1, n+1, letter, array);
		/*
		pixel(m, n-1, letter, array);
		pixel(m-1, n, letter, array);
		pixel(m-1, n-1, letter, array);
		*/
	}
	else
		return;
}
	
	
void printArray(char array[][100], int m, int n)
{

	for(int i=0; i<m; i++)
	{	
		for(int j=0; j<n; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
