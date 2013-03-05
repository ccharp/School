//DogHouse.cpp
//Purpose: practice predefined functions.
//Compute the size of a doghouse that can be purchased given the user's budget.

#include <iostream>
#include <cmath>
using namespace std;

int main( )
{
     const double COST_PER_SQ_FT = 10.50;
     double budget, area, length_side;

     //Get the input data.
     cout << "Enter the amount budgeted for your dog house $";
     cin >> budget;

     //Compute the size.
     area = budget/COST_PER_SQ_FT;
     length_side = sqrt(area);	//function call: sqrt()

     //Set the precision.
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     cout.precision(2);

     //Print the result.
     cout << "For a price of $" << budget << endl;
     Cout << "I can build you a dog house\n"
              << "that is " << length_side << " feet on each side.\n";

     return 0;
}

