#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Nfa {
public:
	Nfa(
		string IniState,
		set<string> &FinStates,
		vector<string> &InptNames,
		vector<map<string, set<string>>> &Transitions
	);

	void convertToDfa();
 	void printNfa();
	void printSet(set<string> &s);
private: 
	string iniState;
	set<string> finStates;
	vector<string> inptNames;
	vector<map<string, set<string>>> transitions;
 
 	bool isFinalState(set<string> s);
	void calcEClosure(set<string> &eClosure);
	string setAlreadyExists(set<string> s, map<string, set<string>> m);
	set<string> calcReachableStates(set<string> setState, string trans);
};
