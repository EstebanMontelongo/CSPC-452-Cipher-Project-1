#include "Vigenere.h"


/**
 * Default constuctor
 */
Vigenere::Vigenere() {
	setAlphabet(string{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" });
}

/**
 * Uses the alphabet to create a map for indexing
 * @param alpha - the alphabet to use.
 * @return - none
 */
void Vigenere::setAlphabet(string alpha) {
	alphabet_ = alpha;
	setAlphaMap();
	setCharMap();
}

/**
 * Pairs each alphabet character with their offset.
 * @param  - none
 * @return - none
 */
void Vigenere::setAlphaMap() {
	for (unsigned int i = 0; i < alphabet_.size(); i++) {
		alphaMap_[alphabet_[i]] = i;
	}
}

/**
 * Pairs an index to a specific character int the alphabet.
 * @param  - none
 * @return - none
 */
void Vigenere::setCharMap() {
	for (unsigned int i = 0; i < alphabet_.size(); i++) {
		charMap_[i] = alphabet_[i];
	}
}

/**
 * Sets the plain text member variable
 * @param  - plain text the user entered.
 * @return - none
 */
void Vigenere::setPlainText(string plainText) {
	plainText_ = toUpperString(plainText);
}

/**
 * Sets the encrypted text member variable
 * @param  - plain text the user entered.
 * @return - none
 */

void Vigenere::setEncryptedText(string cipherText) {
	encryptedText_ = toUpperString(cipherText);
}


//=======================================================================//
//	Description: This function converts a string to all capital letters
//               
//	Input: str - string that will be made into all caps

//	Output: string which is all caps
//======================================================================//
string Vigenere::toUpperString(const string & str){
	/* Sets users key to all caps */
	string newStr = str;
	transform(newStr.begin(), newStr.end(), newStr.begin(), ::toupper);
	return newStr;
}

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& key) {
	/* Sets key to all caps */
	string newKey = toUpperString(key);

	/* Checks to see if each character of the key exists in the alphabet */
	for (auto& c : newKey) {

		if (alphaMap_.find(c) == alphaMap_.end()) {
			return false;
		}
	}
	key_ = newKey;
	return true;
}

//=======================================================================//
//	Description: Sets the autokey we will use for encryption/decryption.
//               
//	Input: none
//	Output: none
//======================================================================//
void Vigenere::setAutoKey() {
	autoKey_ = toUpperString(generateAutoKey());
}

//=======================================================================//
//	Generates an auto key from the original key.
//               
//	Input: none
//	Output: none
//======================================================================//
string Vigenere::generateAutoKey() {
	string autoKey = "";
	if (key_.size() < plainText_.size()) {
		autoKey = key_;
		for (unsigned int i = 0; i < plainText_.size() - key_.size(); i++) {
			autoKey.push_back(plainText_[i]);
		}
	}
	else if (key_.size() > plainText_.size()) {
		for (unsigned int i = 0; i < plainText_.size(); i++) {
			autoKey.push_back(key_[i]);
		}
	}
	else if (key_.size() == plainText_.size()) {
		autoKey = key_;
	}

	return autoKey;
}


/**
 * Helper function for ecrypt/decrypt
 * @param c - a character in the text
 * @return - the offset of the character
 */
int Vigenere::findIndex(char c) {
	if (alphaMap_.find(c) != alphaMap_.end()) {
		return (alphaMap_.find(c))->second;
	}
	return {};
}

/**
 * Helper function for ecrypt/decrypt
 * @param index - the offset of a character
 * @return - the character corresponding to the index
 */
char Vigenere::findCharacter(int index) {
	if (charMap_.find(index) != charMap_.end()) {
		return (charMap_.find(index))->second;
	}
	return {};
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Vigenere::encrypt(const string& plaintext)
{
	/* Sets plain text */
	setPlainText(plaintext);
	/* Generates auto key from users key. */
	autoKey_ = generateAutoKey();

	string encryptedText = "";

	for (unsigned int i = 0; i < plainText_.size(); i++) {
		int index = findIndex(plainText_[i]);
		int offset = findIndex(autoKey_[i]);
		char newChar = findCharacter((index + offset) % alphabet_.size());
		encryptedText.push_back(newChar);
	}
	setEncryptedText(encryptedText);
	return encryptedText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string &cipherText)
{
	string plainText = "";
	setEncryptedText(cipherText);
	autoKey_ = key_;

	for (unsigned int i = 0; i < encryptedText_.size(); i++) {
		int index = findIndex(encryptedText_[i]);
		int offset = findIndex(autoKey_[i]);
		char newChar = findCharacter((alphabet_.size() + (index - offset)) % alphabet_.size());
		plainText.push_back(newChar);
		autoKey_.push_back(newChar);
	}
	setPlainText(plainText);

	return plainText ;
}

