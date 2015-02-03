/*  
 * Program: area.cpp
 * Programmer: Corbin Charpentier
 * Class: EECS168
 * Assignment: Homework 5
 * Date: 11.6.2010
 * Desctiption: Program uses class to calculate area of a rectangle based on use input of heigh and width.
 */

#include <iostream>
#include <cstdlib> 

using namespace std;

//class definition
class Area
{
//Public holds functiosn used to access and manipulate private variables.
public:
	void cal_rectangle_area();
	void set_dimensions(double height,double width);
	void print_area();

//Use cannot directly access private variables
private:
	double height, width, area;
};

int main()
{	
	//variable declarations
	double height, width;
	
	//creates new variable of type 'Area'
	Area area;
	do{
	cout << "Please enter the height and width of a rectangle: "<< endl;
	cin >> height >> width;
	if(height == -999 && width == -999) exit(1);
	area.set_dimensions(height, width);
	area.cal_rectangle_area();
	area.print_area();
	}while (area > 0);
	return 0;
}
//assignes value to private variables
void Area::set_dimensions(double iheight, double iwidth)
{
	height = iheight;
	width = iwidth;
}
//calculates area of rectangle using private variables
void Area::cal_rectangle_area()
{
	area = width*height;
}
//outputs the area
void Area::print_area()
{
	cout << "The area is: " << area << "." << endl;
}
 
