//swap.cpp
//Programmer: Corbin Charpentier
//Descrpetion: Program swatps user designated values using call by reference and again by pointers
//Date Created: 12.6.10

#include <iostream>
using namespace std;

//function prototyptes
void swap_reference(double &walletA, double &walletB);
void swap_pointer(double *walletA, double *walletB);


int main()
{	//variable declarations
	double walletA, walletB;
	cout << "Please enter the amount in wallet 'a'" << endl
	     << "followed by the amount in wallet 'b'." << endl;
	cin >> walletA >> walletB;
	cout << "The amount in 'a' is: " << walletA << endl
	     << "The amount in 'b' is: " << walletB << endl << endl;

	//calls call-by-reference function
	swap_reference(walletA, walletB);
	cout << "After swap call-by-reference, the amount in wallet 'a' is: " << walletA << endl
	     << "And the amount in wallet 'b' is " << walletB << endl << endl;
	
	//calls pointer swap function
	swap_pointer(&walletA, &walletB);	
	cout << "After swap by pointer, the amount in wallet 'a' is: " << walletA << endl
	     << "And the amount in wallet 'b' is :" << walletB << endl << endl;
	
return 0;
}

//uses call-by-reference to swap value of wallet 'a' to wallet 'b' and vice versa
//stores value temporalilary in variable 'tem['
void swap_reference(double &walletA, double &walletB)
{
	double temp;
	temp = walletA;
	walletA = walletB;
	walletB = temp;

}

//functions essentially the same way as 'swap_reference' but uses utilizes pointers.
//NOTE: Program uses variables whose values have already been altered by 'swap_reference'
//	it can be interpreted that this function undoes the swap done in 'swap_reference'.
void swap_pointer(double *walletA, double *walletB)
{
	double temp;
	temp = *walletA;
	*walletA = *walletB;
	*walletB = temp;

}
