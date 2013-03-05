#include "BankAccount.cpp"

//main function 
int main()
{	
	//variable declarations
	int choice;
	double amount;

	//assignes class variables designated values
	BankAccount account1("Corbin", "1233456", 1000.00);

	//outputs user's options
	cout << "Enter a choice: " << endl
	     << "1. Get Customer Name" << endl
	     << "2. Get Account Balance" << endl
	     << "3. Deposit" << endl
	     << "4. Withdrawal" << endl
	     << "5. exit" << endl;
		
	cin >> choice;
	//program runs until 5 is entered
	while(choice != 5)
	{
		//switch statement chooses path based on user input "choice"
		switch(choice)
		{
			case 1:
				cout << "The account belongs to: " << account1.getName() << endl;
				break;
			case 2: 
				cout << "The account balance is: $" << account1.getAmount() << endl;
				break;
			case 3: 
				cout << "Enter the amount you wish to deposit: " << endl;
				cin >> amount;
				cout << "You now have: $" << account1.deposit(amount) << endl;
				break;
			case 4: 
				cout << "Enter the amount you wish ti withdrawal: " << endl;
				cin >> amount;
				cout << "You now have: $" << account1.withdrawal(amount) << endl;
				break;
		
		}
		cout << "Please enter another choice or '5' to exit: " << endl; 
		cin >> choice;
	}
	cout << "PROGRAM TERMINATED\n";
	return 0;
}//end of program
