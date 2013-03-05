#include <iostream>
#include <vector>
#include <string>
#include "BankAccount.h"

using namespace std;

class myBranch
{	
	private:
		//vector used to store objects
		vector <BankAccount> allAccounts;
	public:
		//constructor 
		myBranch(string s1);

		//searches by ssn and finds name of account
		string getAccountName(string ssn);

		//searches by ssn and returns user balance
		double getAccountBalance(string ssn);

		//searches by ssn, returns balance after deposit
		double depositAccount(string ssn, double d1);

		//searches accounts by ssn, returns balance after withdraw
		double withdrawAccount(string ssn, double d1);

		//returns sum of all accounts in a branchs
		double getBranchBalance();
};
