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
#include "Timer.h"

using namespace std;

typedef map<int, unordered_map<string, bool>> Dictionary;

int maxWordSize = 0;

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

	if(word.length() > maxWordSize) {
		maxWordSize = word.length();
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
		
		if(hashHasKey(decrypted, dict[word.length()])) {
			candidates.push_back(key);	
		}
	}

	return candidates;
}

/*vector<string> wordify(string s, Dictionary &dict) {
	// find the largest possible word length
	vector<string> words;
	int maxLen = maxWordSize; 
	int currIndex = 0; 
	bool good = true;

	while(currIndex < s.length() && good) {
		for(int subLen = maxLen; subLen >= 2; subLen--) {

			string subStr = s.substr(currIndex, subLen); 
			//cout << subStr << endl;
				
			if(hashHasKey(subStr, dict[subStr.length()])) {
				words.push_back(subStr);
				currIndex += subLen;
				cout << subStr << endl;

				break; 
			} 
			// else if we can't find a word in the dictionary...
			else if(subLen == 2) {
				good = false;
				break;
			}
		}
	}
}*/

void printWords(vector<string> &words) {
	for(string word : words) {
		cout << word << " ";
	}
	cout << endl;
}

string messageCracker(
	string cipherText, 
	int keyLength, 
	int firstWordLength,
	Dictionary &dictionary
) {
	string firstWord = cipherText.substr(0, firstWordLength);
	vector<string> keyCandidates = crackKey(keyLength, firstWord, dictionary); 

	// For each key...
	for(string key : keyCandidates) {
		string decrypted = viginereCipher(cipherText, key, DECRYPT);

		return decrypted;

		// Assumes each word is in the dictionary
		/*vector<string> words = wordify(decrypted, dictionary);
		printWords(words); */
	}	
}

int main() {
	Dictionary dictionary;
	getDictionary(dictionary);

	string encrypted;
	int keyLen, firstWordLen;
	while(cin >> encrypted) {
		cin >> keyLen >> firstWordLen; 

		Timer timer;
		timer.start();

		string decrypted = messageCracker(
			encrypted,
			keyLen,
			firstWordLen,
			dictionary
		);

		double elapsed = timer.stop();

		cout << "Decrypted: " << decrypted << endl;
		cout << "Duration: " << elapsed << endl;	
	}

	return 0;
}




























