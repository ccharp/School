/*
 *  Bank.cpp
 *
 *  Created by Corbin Charpentier
 *  Contact Email: corbin1@ku.edu
 *  Description: provided an amout to withdrawl or deposit, program will calculate balance of account
 *  Copyright 2010 University of Kansas, EECS Department. All rights reserved 
 *  9/14/10
 *  
 * 
 */

#include <iostream>
using namespace std;

int main()
{

	int choice; 
	double action, balance = 500, result; //action = input for money withdrawn or deposited; result = result of money withdrawn or deposited

	do
	{       //input options
		cout<<"Choose 1 to Withdraw money\n"
		    <<"choose 2 to Deposit money\n"
		    <<"choose 3 to view your balance\n"
		    <<"choose 4 to terminate program\n";
		cin>> choice;

		//switch statement

		switch (choice)
		{
			case 1: //withdraw

				cout<<"How much money would you like to withdraw?  ";
				cin>> action;

			//withdraw calculation
				
				if (action <= balance)
				{						
					result = balance - action;
					cout<<"your new balance is $"<< result <<" after a withdrawal of $" << action<<endl<<endl;
				}
				else if (action > balance)
				{
					cout<<"You do not have enough money in your account for that withdrawl.\n";
				}
				break;

			case 2: //deposit

				result = balance + action;
				cout<<"Your new balance is $"<<result<<" after deposit of "<< action;

				break;

			case 3: //veiw balance

				cout<<"Your balance is $"<<balance;

				break;

			case 4: //treminate program

				cout <<"end of pgoram.\n";

				break;
 
			default: //if input is not valid

				cout<<"not a vailid choice.\n"
				    <<"please input a valid number: 1, 2, 3, or 4\n";
		}
	}while (choice != 4);

return 0;
}
