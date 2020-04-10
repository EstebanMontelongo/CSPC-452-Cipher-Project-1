#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "ErrorHandling.h"
#include "CipherInterface.h"

using namespace std;

/**
 * This class implements the playfair cipher.
 * The class extends the abstract class 
 * CipherInterface.
 */

class Playfair: public CipherInterface
{
	/** The public members **/
	public:

        Playfair();
		virtual bool setKey(const string& key);
		virtual string encrypt(const string& plaintext);
		virtual string decrypt(const string& ciphertext);
			

	/* The protected members */
	protected:
	    string toUpperString(const string & str);
	    string key_;
	    vector<vector<char>> playfairMatrix;
	    string alphabet_;
	    unordered_map<char, vector<int>> originalMap;
	    unordered_map<char, vector<int>> keyMap;
	    void createPlayfairMatrix();
	    void printMatrix();
        void setKeyMap();
		string makeKey(const string &key);



	

};

#endif
