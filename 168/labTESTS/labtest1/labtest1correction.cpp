


#include <iostream>
using namespace std;
int main( )
{
    //N: the number of students, testScore: score, sum: summation of all scores.
    int N, testScore, sum=0, count;
    //ave: Average, grade:A,B,C,D, and F
    double ave;
	char grade;		
	
    cout << "Enter the number of students: ";
    cin >> N;

	

    //Repeat the loop for N times
    for (count=1; count <= N; count++)   
    {
        cout << "Enter the test score: ";
	cin >> testScore;

	if (testScore >= 90 && testScore <= 100) 
	    grade = 'A';
	else if  (testScore >= 80 && testScore < 90)
	     grade = 'B';
	else if  (testScore >= 70 && testScore < 80)
	     grade = 'C';
	else if (testScore >= 60 && testScore < 70)
	     grade = 'D';
	else 
	     grade = 'F';

	cout << "The grade is " << grade << endl; 
	sum = sum + testScore;    
	}
	ave = sum/N;
	cout << "The average of score is "<< ave << endl;
	return 0;
}

