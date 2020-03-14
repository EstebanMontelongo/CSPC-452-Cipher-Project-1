#include "Vigenere.h"


/**
 * Default constuctor
 */
Vigenere::Vigenere() {
	setAlphabet(string{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" });
	setPlainText(string{ "PLAINTEXT" });
	setKey(string{ "KEY" });

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
	plainText_ = plainText;
}

/**
 * Sets the encrypted text member variable
 * @param  - plain text the user entered.
 * @return - none
 */

void Vigenere::setEncryptedText() {
	encryptedText_ = Encrypt();
}


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& key) {

	/* Checks to see if each character of the key exists in the alphabet */
	for (auto& c : key) {

		if (alphaMap_.find(c) == alphaMap_.end()) {
			return false;
		}
	}
	key_ = key;
	/* If valid key set generate auto key from users key. */
	setAutoKey();
	setEncryptedText();
	return true;
}

/**
 * Sets the autokey we will use for encryption/decryption.
 * @param  - none
 * @return - none
 */
void Vigenere::setAutoKey() {
	autoKey_ = generateAutoKey();
}

/**
 * Generates an auto key from the origonal key.
 * @param  - none
 * @return - none
 */
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
	setPlainText(plaintext);
	string encryptedText = "";

	for (unsigned int i = 0; i < plainText_.size(); i++) {
		int index = findIndex(plainText_[i]);
		int offset = findIndex(autoKey_[i]);
		char newChar = findCharacter((index + offset) % alphabet_.size());
		encryptedText.push_back(newChar);
	}
	return encryptedText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText)
{
	setEncryptedText(cipherText);
	string decryptedText = "";

	for (unsigned int i = 0; i < encryptedText_.size(); i++) {
		int index = findIndex(encryptedText_[i]);
		int offset = findIndex(autoKey_[i]);
		char newChar = findCharacter((alphabet_.size() + (index - offset)) % alphabet_.size());
		decryptedText.push_back(newChar);
	}
	return decryptedText;

}

