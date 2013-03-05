//CalculateTax.cpp
//program calculates tax then subtracts it from your total salary

#include <iostream>
using namespace std;

//FUNCTION DECLARATION: before 'main'
double calculate_tax(double salary); 

int main()
{
     double salary, my_tax=0.0, net_income=0.0;
     
     //Input salary.
     cout << "\tThe program calculates your tax." << endl;
     cout << "\tPlease input your salary per month: ";
     cin >> salary;

     //Compute tax and net income.
     my_tax = calculate_tax(salary);  //FUNCTION CALL
     net_income = salary - my_tax;

    //Print the result.
     cout << "\tYour salary is: " << salary << endl;
     cout << "\tYour tax per month is: " << my_tax << endl;
     cout << "\tYour net income  is: " << net_income << endl;

     return 0;
}

//FUNCTION DEFINITION
double calculate_tax (double salary)
{
     const double TAX_RATE = 0.07;
     double tax =0.0;
     tax = salary*0.07;
     return (tax);
}

