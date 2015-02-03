#include <iostream>
#include <vector>
#include <string>
#include "BankAccount.cpp"
using namespace std;

class myBranch
{	
	private:
		vector <BankAccount> allAccounts;
	public:
		myBranch(string s1);
		string getAccountName();
		double getAccountBalance();
		double depositAccount(double d1);
		double withdrawAccount(double d1);
		double getBranchBalance(double d1);
};
