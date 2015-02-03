#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

enum EorD {
	ENCRYPT,
	DECRYPT
};

// Assumes key only contains lower-case alpha characters
string viginereCipher(string plainText, string key, bool e_or_d = ENCRYPT) {
	string ret_val = "";
	unsigned int k_i = 0;

	for(unsigned int p_i = 0; p_i < plainText.size(); p_i++) {
		char p_char = plainText[p_i];
		char k_char = key[k_i];
		
		if(k_i >= key.size() - 1) {
			k_i = 0;
		} else {
			k_i++;
		}
		
		if(!isalpha(p_char)) {
			continue;	
		}	
		
		p_char = isupper(p_char) ? tolower(p_char) - 'a' : p_char - 'a';
		k_char = k_char - 'a';

		char ciphered_char = e_or_d ? p_char - k_char : p_char + k_char;
		
		if(k_char > p_char && e_or_d == DECRYPT) {
			ciphered_char += 26;
		}	

		ciphered_char = (ciphered_char % 26) + 'a';

		ret_val.push_back(ciphered_char);
	}

	return ret_val;
}

/*int main() {
	string plain_text, key;
	bool e_or_d;

	while(true) {
		cout << "Enter a string followed a key:\n";
		cin >> plain_text >> key;
		cout << "Enter 0 for encryption or 1 for decryption:\n";
		cin >> e_or_d;

		string encrypted = viginereCipher(plain_text, key, e_or_d);
		cout << encrypted << endl;
		cout << viginereCipher(encrypted, key, DECRYPT) << endl;
	}

	return 0;
}*/

















