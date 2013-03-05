#include "bankbranch.h"
#include <fstream>



myBranch::myBranch(string s1)
{ 
	ifstream infile(s1.c_str());
	string name, SSN;
	double amount; 
	BankAccount a;
	 
	while(infile >> name, SSN, amount)
	{
		a = BankAccount(name, SSN, amount); 
		allAccounts.push_back (a); 
	}
}

double myBranch::getAccountBalance()
{	
	bool choice = false; 
	string SSN;
	string x = "That SSN was not found";
	cout << "Enter Social Security Number: ";
	cin >> SSN;

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(SSN == allAccounts[i].getSSN)
		{
			return allAccounts[i].getAmount;
			choice = true;
			break;
		}
	}
	if(choice == false){ 
		cout << x; 
	}
}

string myBranch::getAccountName()
{
	string SSN; 
	string x = "That SSN was not found";
	cout << "Enter Social Security Number: ";
	cin >> SSN;

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(SSN == allAccounts[i].getSSN)
		{
			x = allAccounts[i].getName;
			break;
		}
	return x;
	}
}

double myBranch::depositAccount(double d1)
{
	string SSN; 
	string x = "That SSN was not found";
	cout << "Enter Social Security Number: ";
	cin << SSN;

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(allAccounts.getSSN == SSN)
		{
			return allAccounts[i].deposit(d1);
			choice = true;
			break; 
		}
	}
	if(choice == false){ 
		cout << x; 
	}
}

double myBranch::withdrawalAccount(double d1)
{
	string SSN; 
	string x = "That SSN was not found";
	cout << "Enter Social Security Number: ";
	cin << SSN;

	for(int i=0; i < allAccounts[i].size(); i++)
	{
		if(allAccounts.getSSN == SSN)
		{
			return allAccounts[i].withdrawal(d1);
			choice = true; 
			break; 
		}
	}
	if(choice == false){ 
		cout << x; 
	}
}
 
double getBranchBalance()
{
	double totalBalance;
	for(int i=0; i < allAccounts.size(); i++)
	{
		totalBalance = totalBalance + allAccounts[i].getAmount;
	}
	return totalBalance; 
	


	
	
	
	

	

