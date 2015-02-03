//bankaccount.cpp contains function definitions of class BankAccount

//includes bankaccount.h's contents
#include "BankAccount.h" 

//function definitions
BankAccount::BankAccount(string s1, string s2, double d1)
{
	//assigns class variables to construnction names
	name = s1;
	SSN = s2;
	amount = d1;
}
//returns balance of bank account
double BankAccount::getAmount()
{
	return amount;
}

//returns name of account
string BankAccount::getName()
{
	return name;
}

//retuns SSN of account holder
string BankAccount::getSSN()
{
	return SSN;
}

//returns balance of account after deposit of d1
double BankAccount::deposit(double d1)
{
	amount = amount + d1;
	return amount;
}

//returns balance of account after withdrawal of d1
double BankAccount::withdrawal(double d1)
{
	amount = amount - d1;
	return amount;
}

