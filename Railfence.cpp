#include <string>
#include <iostream>
#include "Railfence.h"

bool Railfence::setKey(const string& key) {

	 /* Scans each character and check if its a digit
     * if a non digit is found return false, invalid key */
    for(auto c : key){
        if(!isdigit(c)){
        return false;
        }
    }
	_key = key;
	return true;
}

string Railfence::encrypt(const string& plaintext) {
	string encryptText = "";
	int ptextLength = plaintext.length();
	int rowLength = ptextLength / (stoi(_key));
	int extraRow = ptextLength % (stoi(_key));
	int x = 0;
	int row = 0;

	while (encryptText.length() < plaintext.length()) {
		if (row < extraRow) {
			for (int i = 0; i < rowLength + 1; i++) {
				encryptText = encryptText + plaintext[x];
				x = x + (stoi(_key));
			}
			row++;
			x = row;
		}

		else {
			for (int i = 0; i < rowLength; i++) {
				encryptText = encryptText + plaintext[x];
				x = x + (stoi(_key));
			}
			row++;
			x = row;
		}
	}
	
	return encryptText;


}

string Railfence::decrypt(const string& ciphertext) {
	string decryptText = "";
	int ctextLength = ciphertext.length();
	int rowLength = ctextLength / (stoi(_key));
	int extraRow = ctextLength % (stoi(_key));
	int x = 0;
	int row = 0;
	int count = 0;

	while (decryptText.length() < ciphertext.length()) {
		row = 0;
		x = count;

		for (int i = 1; i < (stoi(_key)) + 1; i++) {
			if (decryptText.length() < ciphertext.length()) {
				decryptText = decryptText + ciphertext[x];
			}
			if (row < extraRow) {
				x = x + rowLength + 1;
			}
			else {
				x = x + rowLength;
			}
			row++;
		}
		count++;
	}

	return decryptText;

}
