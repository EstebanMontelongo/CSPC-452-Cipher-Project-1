#ifndef VIGENERE_H
#define VIGENERE_H

#include <unordered_map>
#include <algorithm> 
#include "ErrorHandling.h"
#include "CipherInterface.h"

using namespace std;

/**
 * This class implements the vigenere cipher.
 * The class extends the abstract class
 * CipherInterface.
 */

class Vigenere : public CipherInterface
{
	/** The public members **/
public:

	Vigenere();
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

protected:
	string autoKey_;
	string alphabet_;
	string key_;
	string encryptedText_;
	string plainText_;
	unordered_map<char, int> alphaMap_;
	unordered_map<int, char> charMap_;

	void setPlainText(string plainText);
	void setEncryptedText(string cipherText);
	void setAlphabet(string alpha);
	void setAlphaMap();
	void setCharMap();
	void setAutoKey();
	string toUpperString(const string &str);
	
	string generateAutoKey();
	int findIndex(char c);
	char findCharacter(int index);


};

#endif
