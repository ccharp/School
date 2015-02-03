//      Program name: area.cpp
//	Author: Corbin Charpentier      ID: 2294563
//	Date written: 9/29/2010
//	Desctiption: Program uses functions to calculate area of circles, rectangles and squares based on user input. 



#include <iostream>
#include <cmath>
using namespace std;





//Function declarations
double area(double radius);
double area(double length, double width);
float area(float side);

const double pi = 3.14159;

int main()
{

     double radius, length, width;        //For circle and rectangle
     double circle_area, rectangle_area;  //For rectangle
     float side, square_area;             //For square
     
     //user input length input and area output
	//area of circle
	cout<<"Please the radius of the circle:\n";  
	cin>>radius;
	cout<<"the area is: "<< area(radius)<<endl<<endl;
	
	//area of rectangle
	cout<<"Please enter the length followed the the width of a rectangle:\n";
	cin>>length>> width;
	cout<<"the area is: "<< area(length, width)<<endl<<endl;

	//area of square
	cout<<"please enter the side of a square:\n";
	cin>>side;
	cout<<"the area is: " << area(side)<<endl<<endl;
     
     return 0;
}

//functions

double area(double radius)//circle area
{
	double circle_area;
	circle_area=pi*radius*radius; ///area of circle: A=Pi(radius)^2
	return(circle_area);
}

double area(double length, double width)//retangle area: A=Length*width
{
	double rectangle_area;
	rectangle_area=length*width;
	return(rectangle_area);
}

float area(float side)//square area
{
	double square_area;
	square_area=side*side; //area of square: A=side^2
	return(square_area);
}


