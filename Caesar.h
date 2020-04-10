#ifndef CAESAR_H
#define CAESAR_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <iostream>  /* For standard I/O */
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <algorithm>
#include "ErrorHandling.h"
#include "CipherInterface.h"

using namespace std;
//
/**
 * This class implements the caesar cipher.
 * The class extends the abstract class
 * CipherInterface.
 */

class Caesar : public CipherInterface
{
	/** The public members **/
public:

	Caesar();
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

	/* The protected members */
protected:
	string alphabet_;
	int key_;
	unordered_map<char, int> alphaMap_;
	unordered_map<int, char> charMap_;
	
	void setAlphaMap();
	void setCharMap();
	int findIndex(char c);
	char findCharacter(int index);
	void setAlphabet(string alpha);
	string toUpperString(const string &str);
};

#endif
