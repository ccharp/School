#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>

#include <boost/lexical_cast.hpp>

#define sw setw(10)

#include "Nfa.h"

using namespace std;

Nfa::Nfa(
	string IniState,
	set<string> &FinStates,
	vector<string> &InptNames,
	vector<map<string, set<string>>> &Transitions
	) :
	iniState(IniState),
	finStates(FinStates),
	inptNames(InptNames),
	transitions(Transitions)
{
}

string incStr(string &str) {
	int i = atoi(str.c_str());
	str =  boost::lexical_cast<string>(++i);
	return str;
}

bool Nfa::isFinalState(set<string> s) {
	for(auto state : s) {
		for(auto fstate : finStates) {
			if(state == fstate) {
				return true;
			}
		}
	}
	return false;
}

void Nfa::convertToDfa() {
	string name = "1";
	set<string> finalStates;
	vector<map<string, string>> dfa;
	map<string, string> tmp; 
	dfa.push_back(tmp);

	//maps a new name to it's corresponding set of states
	map<string, set<string>> nameToSet;
	//keeps track of new states we've explored
	queue<string> qNewStates;

	set<string> eClosure;
	eClosure.insert(name);
	calcEClosure(eClosure);
	nameToSet[name] = eClosure;
	qNewStates.push(name);

	cout << "E-closure(IO) = "; printSet(eClosure);
	cout << " = " << boost::lexical_cast<string>(name);
	cout << endl << endl;

	while(!qNewStates.empty()) {
	//for(int x = 0; x < 7; x++) {
		map<string, string> mapTrans; //note that we don't need set<string> here 
									  // because a DFA move only to a single explicit
									  // state per input. 

		string state = qNewStates.front(); qNewStates.pop();
		cout << "Mark " << state << endl;

		//for each possible transition, calculate reachable nodes
		for(int i = 0; i < inptNames.size() - 1; i ++) {
			string transition = inptNames[i];

			set<string> reachables = calcReachableStates(nameToSet[state], transition);

			//if there are reachable states, continue
			if(reachables.empty())
				continue;

			printSet(nameToSet[state]);
			cout << " --" << transition << "--> "; printSet(reachables);
			cout << endl;

			set<string> eClosure = reachables;
			calcEClosure(eClosure); 
			
			cout << "E-Closure"; printSet(reachables); cout << " = "; printSet(eClosure);

			//check if this set of states already exists
			//	this variable also encodes the state name of the 
			//	duplicate if it exists
			string isDuplicate = setAlreadyExists(eClosure, nameToSet);
			if(isDuplicate == "0") {
				cout << " = " << incStr(name) << endl;
				nameToSet[name] = eClosure;
				qNewStates.push(name);

				if(isFinalState(eClosure)){
					finalStates.insert(name);
				}
			} else {
				cout << " = " << isDuplicate << endl;
			}
			//add entry in state for the transition
			mapTrans[transition] = name;
		}
		dfa.push_back(mapTrans);
		cout << endl;
	}
	
	//print the dfa
	cout << "Initial State: {1}" << endl;
	cout << "Final States: "; printSet(finalStates);
	cout << "\nState";// << setw(10);
	for(int i = 0; i < inptNames.size() - 1; i++) {
		cout << setw(10) << inptNames[i]; 
	}
	cout << endl; 
	for(int i = 1; i < dfa.size(); i++) {
		cout << i << setw(10); 
		for(int j = 0; j < inptNames.size() - 1; j++) { 
			cout << setw(10);
			cout << "{" << dfa[i][inptNames[j]] << "}";
		}
		cout << endl;
	}
	cout << endl;
}

//This is the very expensive way to do this check. A cheaper version
//	involes hashing each unique set and mapping it to a boolean. This 
//	way was simply quickest to implement. 
string Nfa::setAlreadyExists(set<string> s, map<string, set<string>> m) {
	for(auto elem : m) {
		set<string> sm = elem.second;
		if(s.size() != sm.size()){
			continue;
		}

		set<string>::iterator it_s  = s.begin();
		set<string>::iterator it_sm = sm.begin();
		bool duplicate = true;
		for( ; it_s != s.end(); it_s++, it_sm++) {
			duplicate = duplicate && *it_s == *it_sm; 	
		}
		if(duplicate) {
			return elem.first;
		}
	}
	return "0";
}

set<string> Nfa::calcReachableStates(set<string> setState, string trans) {
	set<string> setRet;
	for(auto state : setState) {
		int i = atoi(state.c_str());

		set<string> possibleMoves = transitions[i][trans];
		for(auto moveState : possibleMoves) {
			setRet.insert(moveState);
		}
	}
	return setRet;
}

void Nfa::calcEClosure(set<string> &eClosure) {
	for(auto s : eClosure) {
		for(auto state : transitions[atoi(s.c_str())]["E"]) {
			//check to see if that state already exists in the closure
			//	so we don't infinitely recurse
			if(eClosure.find(state) != eClosure.end())  
				continue;
			eClosure.insert(state);
			calcEClosure(eClosure);
		}
	}
}

void Nfa::printSet(set<string> &s) {
	set<string>::iterator it = s.begin();

	cout << "{";
	cout << *it;
	for(it++; it != s.end(); it++) {
		cout << "," << *it;
	}
	cout << "}";
}

void Nfa::printNfa() {
	cout << "Initial State: {" << iniState << "}\n";
	cout << "Final States: "; printSet(finStates);
	
	//print states
	cout << "\nState";
	for(auto state : inptNames) {
		cout << sw << state;
	}
	cout << endl;

	//print transitions
	for(int i = 1; i < transitions.size(); i++){
		cout << i << setw(10); 
		for(auto state : inptNames) {
			cout << setw(10);
			printSet(transitions[i][state]);
		}
		cout << endl;
	}
}


























