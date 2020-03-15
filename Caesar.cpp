#include "Caesar.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <typeinfo>

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{
	_key = key;
	stringstream val(_key); //converts the key into an
	int keyint = 0;         //int to make encryption
	val >> keyint;          //easier
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
	string ptext=plaintext;
	int ptextLength = plaintext.length();

  for (int i = 0; i<ptextLength; i++)
  {
    if(isupper(ptext[i])){
	    encryptText += char(int(ptext[i]+keyint-65)%26+65);
    }
    else{
	    encryptText += char(int(ptext[i]+keyint-97)%26+97);
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
	    decryptText += char(int(ctext[i]+keyint-65)%26+65);
    }
    else{
	    decryptText += char(int(ctext[i]+keyint-97)%26+97);
    }
  }
	return decryptText;
}
