#include "Caesar.h"


/**
 * Default constructor
 */
Caesar::Caesar(){
  setAlphabet(string{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"});
}


/**
 * Uses the alphabet to create a map for indexing
 * @param alpha - the alphabet to use.
 * @return - none
 */
void Caesar::setAlphabet(string alpha) {
	alphabet_ = alpha;
	setAlphaMap();
	setCharMap();
}

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{
  /* key must also be in range 0 <= key <= 25,
    * so it key length must be 1 <= key.size() <= 2 */
  if(key.size() == 0 || key.size() >= 3){
      return false;
  }
  /* Scans each character and check if its a digit
    * if a non digit is found return false, invalid key */
  for(auto c : key){
    if(!isdigit(c)){
      return false;
    }
  }
  /* Converts string to int */
  stringstream iss(key);
  int keyValue;

	iss >> keyValue;
	if(iss.fail()){
	    return false;
	}

	if(keyValue < 0 || keyValue > 25){
	    return false;
	}

	key_ = keyValue;
  cout << key_ << endl;

	return true;
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{
	string encryptText = "";
  string plainText = toUpperString(plaintext);
	
  for(auto c : plainText){
    int index = findIndex(c);
    char newChar = findCharacter((index + key_) % alphabet_.size());
    encryptText.push_back(newChar);
  }
	
	return encryptText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& ciphertext)
{
	string decryptText = "";
  string cipherText = toUpperString(ciphertext);

	for(auto c : cipherText){
    int index = findIndex(c);
    char newChar = findCharacter((alphabet_.size() + (index - key_)) % alphabet_.size());
    decryptText.push_back(newChar);
  }
	return decryptText;
}

/**
 * Pairs each alphabet character with their offset.
 * @param  - none
 * @return - none
 */
void Caesar::setAlphaMap() {
	for (unsigned int i = 0; i < alphabet_.size(); i++) {
		alphaMap_[alphabet_[i]] = i;
	}
}

/**
 * Pairs an index to a specific character int the alphabet.
 * @param  - none
 * @return - none
 */
void Caesar::setCharMap() {
	for (unsigned int i = 0; i < alphabet_.size(); i++) {
		charMap_[i] = alphabet_[i];
	}
}

/**
 * Helper function for ecrypt/decrypt
 * @param c - a character in the text
 * @return - the offset of the character
 */
int Caesar::findIndex(char c) {
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
char Caesar::findCharacter(int index) {
	if (charMap_.find(index) != charMap_.end()) {
		return (charMap_.find(index))->second;
	}
	return {};
}

//=======================================================================//
//	Description: This function converts a string to all capital letters
//               
//	Input: str - string that will be made into all caps

//	Output: string which is all caps
//======================================================================//
string Caesar::toUpperString(const string & str){
	/* Sets users key to all caps */
	string newStr = str;
	transform(newStr.begin(), newStr.end(), newStr.begin(), ::toupper);
	return newStr;
}
