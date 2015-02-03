#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <sstream>

#include "Nfa.h"

using namespace std;

int main()
{
	string str;
	stringstream ss; 

	//get initial state
	cin >> str >> str >> str; 
	string iniState = str.substr( 1, str.size() - 2);

	//get final states: 
	set<string> finStates;  
	cin >> str >> str >> str; 
	//str = str.substr( 1, str.size() - 2);
	//finStates.insert(str);
	if(str.size() > 2) {
		str = str.substr(1, str.size() - 2);
		ss << str; 
		cout << "HERE";
		while(getline(ss, str, ',')) {
			finStates.insert(str);	
		}
		ss.clear();
	}else{
		cout << "ERROR: no final states\n";
		exit(0);
	}

	//get total states;
	cin >> str >> str >> str;
	int numStates = atoi(str.c_str()); 

	//get state names 
	cin >> str;
	vector<string> inptNames;
	while(cin >> str && isalpha(str[0])) {
		inptNames.push_back(str); 
	}

	//get the transition sets
	int numPaths = inptNames.size();
	vector<map<string, set<string>>> transitions;

	//push back an empty map to keep indexing consistant with state names
	map<string, set<string>> tmp;
	transitions.push_back(tmp);
	for(int i = 1; i <= numStates; i++) {
		map<string, set<string>> mapTrans; 		
		for(auto j : inptNames) {
			cin >> str;

			//parse any integers out str
			if(str.size() > 2) {
				set<string> setPaths;
				str = str.substr(1, str.size() - 2);
				ss << str; 
				while(getline(ss, str, ',')) {
					setPaths.insert(str);	
				}
				mapTrans[j] = setPaths;
				ss.clear();
			}
		}
		transitions.push_back(mapTrans);
		cin >> str; //move past state name
	}

	Nfa nfa(
		iniState,
		finStates,
		inptNames,
		transitions
	);

	nfa.convertToDfa();
	
	return 0;
}




















