#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;

// Only returns on error
void mainLoop();

void printPrompt();

Job parseInput(string input); 

QuashCmds isShellCommand(input); 

char **tokenize(string str, char **args);


int main(int argc, char **argv, char **envp) {
	// Set up signals
	// Set up environment		
	// Should initialzie Quash object.
	// Pass conrtol to Quash who starts main moop
}

void mainLoop() {
	while(1) {
		printPrompt();

		string input;
		getline(cin, input);

		// Tokenize input on spaces 
		char **args = NULL;
		tokenize(input, args); 

		if(!args) {
			cout << "Error in mainLoop\n";
			continue; 
		}

		// Determine if the command is a binary to be executed 
		// or a shell command
		if(isShellcommand(args)) {
			
		} else {
			Job job = parseJob(input);	
			job.execute(); 	
		}	
	}
}

Job parseJob(string input) {
		
}

void printPrompt() {
	char *cwd = get_current_dir_name(); 
	cout << "Quash " << cwd << "\n$ ";	
	delete []cwd;
}

QushCmds isShellCommand(char **args) {
	bool retVal = NOT_QUASH_CMD;

	if("cd" == args[0])
		retVal = CD;
	else if("set" == args[0])
		retVal = SET;
	else if("exit" == args[0])
		retVal = EXIT;
	else if("quit" == args[0])
		retVal = QUIT;
	else if("jobs" == args[0])
		retVal = JOBS;
	
	return retVal;	
}

// Assumes perfectly delimited input
char **tokenize(string str, char **args) {

	vector<string> words;
	stringstream ss(str);

	string word;
	while(ss) {
		ss >> word; 
		words.push_back(word);		
	}

	// Now we can allocate and fill args
	args = new char[words.size() + 1]; 
	for(int i = 0; i < words.size(); i++) {
		args[i] = words[i].c_str(); 	
	}

	// Null Terminate the array for exec
	args[words.size()] = NULL; 
}













































