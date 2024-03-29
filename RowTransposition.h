#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <iostream>
#include <cctype>
#include <unordered_map>
#include "ErrorHandling.h"
#include "CipherInterface.h"

using namespace std;

/**
 * This class implements the row transposition cipher.
 * The class extends the abstract class
 * CipherInterface.
 */

class RowTransposition : public CipherInterface
{
	/** The public members **/
public:

	/**
	 * Sets the key to use
	 * @param key - the key to use
	 * @return - True if the key is valid and False otherwise
	 */
	virtual bool setKey(const string& key);

	/**
	 * Encrypts a plaintext string
	 * @param plaintext - the plaintext string
	 * @return - the encrypted ciphertext string
	 */
	virtual string encrypt(const string& plaintext);

	/**
	 * Decrypts a string of ciphertext
	 * @param ciphertext - the ciphertext
	 * @return - the plaintext
	 */
	virtual string decrypt(const string& ciphertext);

protected:
	string _key;

};

#endif
