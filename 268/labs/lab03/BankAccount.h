//Is header file for main.cpp. backaccount.h provides bankaccount.cpp and main.cpp with class BankAccount

#include <iostream> 
#include <string>
using namespace std;

//Class definition
class BankAccount
{
	private: 
		string name;
		string SSN;
		double amount;
	public:
		//BankAccount construction
		BankAccount();
		BankAccount(string s1, string s2, double d1);

		//returns acount balance
		double getAmount();

		//returns name of the account
		string getName();
		
		//retuns SSN of account holder
		string getSSN();

		//returns the blance of account after deposit of d1
		double deposit(double d1);

		//returns balance of account after withdrawal of d1
		double withdrawal(double d1);
};
