#include <iostream>
#include <stdlib.h>
#include "bankbranch.h"

using namespace std;

int main(int argc, char* argv[])
{
	int choice;
        string ssn;
        int amount;
	
       /* if(argc < 2)
        {
            cout << "lab3 inputFile" << endl; 
            exit(0);
        }*/
        string file1(argv[1]);
       
        myBranch bankbranch(file1);
  
        cout << "1. Get Customer Name" << endl;
	cout << "2. Get Account Balance" << endl;
	cout << "3. Deposit" << endl;
	cout << "4. Withdraw" << endl;
	cout << "5. Get the Total Balance for the Branch" << endl;
	cout << "6. Exit" << endl << endl;
        cout << "Enter choice:" << endl;
	cin  >> choice;

	do
	{
                if(choice == 1)
                {
                   cout << "Enter ssn:\n";
                   cin >> ssn;
                   cout << "The name of the customer is " << bankbranch.getAccountName(ssn) << endl;
              
                }
                else if(choice == 2)
                {
                   cout << "Enter ssn:\n";
                   cin >> ssn;
                   cout << "The balance on the account is " << bankbranch.getAccountBalance(ssn) << endl;
              
                }
                else if(choice == 3)
                {
                   cout << "Enter ssn:\n";
                   cin >> ssn;
                   cout << "Enter amount for deposit:\n";
                   cin >> amount;
                   bankbranch.depositAccount(ssn, amount);
                   cout << "The new balance on the account is " << bankbranch.getAccountBalance(ssn) << endl;              
                }
                else if(choice == 4)
                {
                   cout << "Enter ssn:\n";
                   cin >> ssn;
                   cout << "Enter amount for withdraw:\n";
                   cin >> amount;
                   bankbranch.withdrawAccount(ssn, amount);
                   cout << "The new balance on the account is " << bankbranch.getAccountBalance(ssn) << endl;              
                }
                else if(choice == 5)
                {
                   cout << "The total balance on the accounts is " << bankbranch.getBranchBalance() << endl;              
                }

                cout << "Enter choice:" << endl;
		cin  >> choice;

	}
	while(choice != 6);
 
	return 0;
}


