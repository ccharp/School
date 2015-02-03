//Name: Corbin Charpentier
//Student ID: 2294563

#include <iostream>
#include <cmath>
using namespace std;

void getPoints (int &x1, int &x2, int &y1, int &y2);
double dist(double x1, double x2, double y1, double y2);
double dist(double x2, double y2);
void printOutput(int perimeter, int side1, int side2, int side3);


int main()
{
	int x1, x2, y1, y2;
	double side1, side2, side3, perimeter;	

	getPoints(x1, x2, y1, y2);

	side1 = dist(x1, x2, y1, y2);
	side2 = dist(x2, y2);
	side3 = dist(x1, y1);
	perimeter = side1 + side2 + side3;

	printOutput(perimeter, side1, side2, side3);

return 0;
}

void getPoints (int &x1, int &x2, int &y1, int &y2)
{
	cout << "Please enter and both x coordinates followed by both y coordinates: ";
	cin >> x1 >> x2 >> y1 >> y1;
}

double dist(double x1, double x2, double y1, double y2)
{
	return(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

double dist(double x, double y)
{
	return(sqrt((x*x+y*y)));
}

void pintOutput(int perimeter, int side1, int side2, int side3)
{
	cout << "The length of side 1 is: " << side1 << endl;
	cout << "The length of side 2 is: " << side2 << endl;
	cout << "The length of side 3 is: " << side3 << endl;
	cout << "The perimeter of the triangle is: " << perimeter << endl;
}







