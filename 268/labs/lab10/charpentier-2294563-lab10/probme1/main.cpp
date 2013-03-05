#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int recpower(int num, int power, int multiplyer);

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
		exit(1);
	}
	ofstream fout(output.c_str());
	if(fin.fail()){
		cout << "output failed to open" << endl;
		exit(1);
	}
	int multiplyer, power, num;
	while(fin >> multiplyer)
	{
		fin >> power;
		num = multiplyer;
		cout << recpower(num, power, multiplyer) << endl;
	}
	return 0;
}

int recpower(int num, int power, int multiplyer)
{
	if(power == 1)
		return num;
	else
	{
		return(recpower(num*multiplyer, power-1, multiplyer));
	}
}
