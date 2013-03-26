#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <map>
#include <unistd.h>
#include <algorithm>

#include "viginere.cpp"

using namespace std;

typedef map<int, unordered_map<string, bool>> Dictionary;

void getDictionary(Dictionary &dictionary) {
	ifstream inFile("dict.txt");
	if(inFile.fail()) {
		cout << "Problem opening file. Exiting\n";
		exit(0);
	}

	unordered_map<string, bool> uMap;
	string word;

	// Get the first word
	inFile >> word;
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	int prevWordSize = word.length();
	uMap[word] = true;

	while(inFile >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		
		if(word.length() != prevWordSize && !uMap.empty()) {
			dictionary[prevWordSize] = uMap;	
			prevWordSize = word.length();
			uMap.clear();
		}
		
		uMap[word] = true;
	}	

	// Add the last word length
	dictionary[word.length()] = uMap;	
}

void printDictionary(Dictionary &dictionary) {
	for(auto uMap : dictionary) {
		for(auto w : uMap.second) {
			cout << w.first << endl;	
		}	
	}
}

int incIndex(int limit, int i) {

	if(++i >= limit) {
		i = 0;	
	}

	return i;
}

void generatePermutations(string s, vector<string> &ss) {

	string goal;
	// Generate termination string
	for(int i = 0; i < s.length(); i++) {
		goal.push_back('z');	
	}

	while(s != goal) {
		
		//cout << s << endl;
		s[0] += 1;
		
		// If we need to carry
		if(s[0] > 'z') {
			s[0] = 'a';
			
			for(int i = 1; i < s.length(); i++) {
				if(s[i] >= 'z' && i != s.length() - 1) {
					s[i] = 'a';	
				} else {
					s[i] += 1;
					break;	
				}	
			}			
		}
		
		ss.push_back(s);
	}
}

void generateKeys(int length, vector<string> &keys) {
	string key;

	// Generate first word
	for(int i = 0; i < length; i++) {
		key.push_back('a');	
	}

	keys.push_back(key); 

	generatePermutations(key, keys);
}

bool hashHasKey(string &word, unordered_map<string, bool> &uMap) {
	auto uMapIter = uMap.find(word); 

	if(uMapIter == uMap.end()) {
		return false;	
	}

	return true;
}

vector<string> crackKey(int keyLen, string word, Dictionary &dict) {
	
	// Generate all possible keys of length keyLen
	vector<string> keys;
	generateKeys(keyLen, keys); 

	// Find all possible keys
	vector<string> candidates;
	for(string key : keys) {
		string decrypted = viginereCipher(word, key, DECRYPT);	
		
		//cout << candidate << endl;
		
		if(hashHasKey(decrypted, dict[word.length()])) {
			candidates.push_back(key);	
			cout << "Possible password: " << decrypted << endl;
		}
	}

	return candidates;
}

void passwordCracker(
	string cipherText, 
	int keyLength, 
	int firstWordLength,
	Dictionary &dictionary
) {
	string firstWord = cipherText.substr(0, firstWordLength);
	vector<string> keyCandidates = crackKey(keyLength, firstWord, dictionary); 

	// For each key...
	for(string key : keyCandidates) {
		cout << key << endl;	
	}	
}

int main() {
	Dictionary dictionary;

	getDictionary(dictionary);

	passwordCracker(
		"MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX",
		2,
		6,
		dictionary
	);

	return 0;
}




























