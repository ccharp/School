//      Program name: review.cpp
//	Author: Corbin Charpentier      ID: 2294563
//	Date written: 9/29/2010



//Computes the area of a circle and the volume of a sphere.
//Uses the same radius for both calculations.
//Area = PI*<math>r^2</math>
//Volume = 3/4*PI*<math>r^3</math>
//Use predefined function, pow() in your code

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

//Function definition
double area(double radius_of_both);
double volume(double radius_of_both);
double rectangle;

int main()
{
     double radius_of_both, area_of_circle, volume_of_sphere;
    
     cout <<"Enter a radius to use for both a circle and a sphere: " << endl;
     cin >> radius_of_both;


	//calculates area of circle using circle area(radius) function
     area_of_circle = area(radius_of_both);


	//calculates volume of sphere using volume(radius)
     volume_of_sphere = volume(radius_of_both);


//area and volume output
     cout << "Radius = " <<  radius_of_both << " inches" << endl;
     cout << "Area of circle = " << area_of_circle << endl;
     cout << "Volume of sphere = " << volume_of_sphere << endl;

     return 0;

}

//Function for Area

double area(double radius_of_both)
{
	double area; //area is calculated with the formula: A = Pi(radius)^2 
	area = radius_of_both*PI*radius_of_both;
	return(area);
}


//Function for Volume

double volume(double radius_of_both)
{
	double volume; //volume is calculated with the formula: V = (4/3)Pi(radius)^2
	volume = (4.0/3.0)*PI*radius_of_both*radius_of_both*radius_of_both;
	return(volume);
}



























