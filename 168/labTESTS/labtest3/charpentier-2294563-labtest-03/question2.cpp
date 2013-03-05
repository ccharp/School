
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;



void findnumbers(ofstream& out, ifstream& in1, ifstream& in2);


int main()
{
	
	ifstream in1, in2;
	in1.open("text.dat");
	in2.open("text.dat");
	
	if(in1.fail()&&in2.fail())
	{
		cout << "Opening failed";
		exit(1);
	}
	
	
	ofstream out;
	out.open("results.txt");
	if(out.fail())
	{
		cout << "opening failed";
		exit(1);
	}

	
	findnumbers(out,in1,in2);

	out.close();
	in1.close();
	in2.close();

	return 0;
}

void findnumbers(ofstream& out, ifstream& in1, ifstream& in2)
{
	
	char next, space = ' ', line = '\n';
	

        int withspacecount = 0, spaces = 0, lines = 0, withoutspaces;

		
	while(in1 >> next)
	{
		withspacecount++;
		
		if(next == ' ')
			spaces++;
			cout << spaces;
		if(next == line)
			lines++;
	
	}
	
	withoutspaces = withspacecount - spaces;

	out << "There are " << withspacecount << " characters including spaces in the file.\n";
	out << "THere are " << withoutspaces << " characerst not including spaces.\n";
	out << "There are " << lines << " number of lines in the text\n";
}











