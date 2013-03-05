// EmailSetUp.cpp.
#include <iostream>
#include <cstring>
using namespace std;

// Declaration of Constant Variables
const int USRNM_MAX_SIZE = 12;
const int SERVER_LEN = 20;

bool createUsrname(char usrname[]);
bool chooseEmailServer(char emailserver[]);
void createEmailAccount(char usrname[], char emailserver[], char emailaddress[]);
void outputEmailAddress(char usrname[], char emailserver[], char emailaddress[]);

int main()
{
    char usrname[USRNM_MAX_SIZE+1], emailserver[SERVER_LEN+1], emailaddress[USRNM_MAX_SIZE+SERVER_LEN+1];
    bool isusrnamevalid = false;
    bool isservervalid = false;

    cout << "==== Create UserName ====\n";
    while(!isusrnamevalid)
        isusrnamevalid = createUsrname(usrname);
    
    cout << "==== Choose an Email Server ====\n";
    while(!isservervalid)
		isservervalid = chooseEmailServer(emailserver);
	
    // ==== Create an Email Address ====
    createEmailAccount(usrname, emailserver, emailaddress);

    cout << "==== Output Email Information ====\n";
    outputEmailAddress(usrname, emailserver, emailaddress);
    
    return 0;
}

bool createUsrname(char usrname[]){
    cout << "Please create a username with length between 6-12 characters: ";
    cin >> usrname;

    if(strlen(usrname) < 6){
        cout << "Your Username is too short.\n";
	return false;
    }
    else if(strlen(usrname) > 12){
	cout << "Your Username is too long.\n";
	return false;
    }
    else{
	cout << "Your input username is valid.\n";
	return true;
    }
}

bool chooseEmailServer(char emailserver[]){
    char option[SERVER_LEN+1];
    cout << "Please choose an email server listed as follows:\n"
             << "---------------------------------------------------\n"
	     << "GMAIL for gmail\n"
	     << "HOTMAIL for hotmail\n"
	     << "YAHOO for yahoo\n"
             << "---------------------------------------------------\n";
    cin >> option;
    
    if(strcmp(option, "GMAIL") == 0){
        strcpy(emailserver, "@gmail.com");
	return true;
    }
    else if(strcmp(option, "HOTMAIL") == 0){
	strcpy(emailserver, "@hotmail.com");
	return true;
    }
    else if(strcmp(option, "YAHOO") == 0){
	strcpy(emailserver, "@yahoo.com");
	return true;
    }
    else{
	cout << "Your choice is invalid.\n";
	return false;
    }
}

void createEmailAccount(char usrname[], char emailserver[], char emailaddress[]){
    strcpy(emailaddress, usrname);

    strcat(emailaddress, emailserver);

    // INSERT YOUR CODE: Concatecate emailserver onto the end of emailaddress

}

void outputEmailAddress(char usrname[], char emailserver[], char emailaddress[])
{
    cout
	 << "User Name: " << usrname << endl
	 << "Welcome to " << emailserver << endl
	 << "Your Email account is " << emailaddress << endl; 

}























