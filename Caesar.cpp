#include "Caesar.h"
#include <typeinfo>

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
    istringstream iss(key);
    int keyValue;

	iss >> keyValue;
	if(iss.fail()){
	    return false;
	}

	if(keyValue < 0 || keyValue > 25){
	    return false;
	}

	key_ = keyValue;
	return (typeid(keyint) == typeid(int)); //will return true if keyint is an integer false otherwise
						// should always return true
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{
	string encryptText = "";
	int ptextLength = plaintext.length();

  {
    if(isupper(ptext[i])){
    }
    else{
    }
  }
	return encryptText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText)
{
	string decryptText = "";
	string ctext=cipherText;
  	int ctextLength = cipherText.length();

  for (int i = 0; i<ctextLength; i++)
  {
    if(isupper(ctext[i])){
    }
    else{
    }
  }
	return decryptText;
}
