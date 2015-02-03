#include "bankbranch.h"
#include <fstream>
#include <cstdlib>
using namespace std; 

//CONSTRUCTOR: opens input file and fills vector with objects
myBranch::myBranch(string s1)
{ 
	ifstream infile;
	infile.open("input.txt");
	if(infile.fail())
	{cout << "suck it" << endl; exit(0);}
	string name, SSN;
	double amount; 
	 
	while(infile >> name)//loop runs until last name is read
	{	
		infile >> SSN;
		infile >> amount; 
		BankAccount a = BankAccount(name, SSN, amount); //conscturcts object based on input from input file
		allAccounts.push_back(a); 
	}
}

//Searches accounts by SSN and returns balance of account
double myBranch::getAccountBalance(string ssn)
{	
	//Default message
	string x = "That SSN was not found";

	//SSN search loop. searches all objects for correct SSN.
	for(int i=0; i < allAccounts.size(); i++)
	{
		if(ssn == allAccounts[i].getSSN())
		{
			return allAccounts[i].getAmount();
		}
	}
	cout << x;
	return 0; 
}

//Searches accounts by SSN and returns name of account
string myBranch::getAccountName(string ssn)
{
	string x = "That SSN was not found";

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(ssn == allAccounts[i].getSSN())
		{
			return allAccounts[i].getName();
		}
	return x;
	}
}

//searches accounts by SSN and returns balance of account after deposit 'd1'
double myBranch::depositAccount(string ssn, double d1)
{ 
	string x = "That SSN was not found";

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(allAccounts[i].getSSN() == ssn)
		{
			return allAccounts[i].deposit(d1); //calls deposit(): adds amout 'd1' to current balance
		}
	}
	cout << x;
	return 0; 
}

//Function same as depositAccount except subtracts money from balance
double myBranch::withdrawAccount(string ssn, double d1)
{
	string x = "That SSN was not found";

	for(int i=0; i < allAccounts.size(); i++)
	{
		if(allAccounts[i].getSSN() == ssn)
		{
			return allAccounts[i].withdrawal(d1);
		}
	}
	cout << x;
	return 0; 
}
 
//Adds balance of all accounts within the branch
double myBranch::getBranchBalance()
{
	double totalBalance;
	for(int i=0; i < allAccounts.size(); i++)
	{
		totalBalance = totalBalance + allAccounts[i].getAmount();
	}
	return totalBalance; 
}
	


	
	
	
	

	

