#ifndef __MAIN_FUNCTIONS__
#define __MAIN_FUNCTIONS__
#define REQ_ARGS 6	

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <unordered_set>

#include "ErrorHandling.h"
#include "Caesar.h"
#include "CipherInterface.h"
#include "Playfair.h"
#include "Railfence.h"
#include "RowTransposition.h"
#include "Vigenere.h"
#include "HillCipher.h"



using namespace std;

/*
* These are the implamentations of a few helper functions for main
*/
 
/* Creating a set for all available ciphers */
const unordred_set<string> cipherNames = { "PLF", "RTS", "RFC", "VIG", "CES", "HILL" };

/* Function prototypes */
void checkNumArgs(int argc);
void checkArgs(string &cipherName, string &ENC_DEC, string &inputFile, string &outFile);
void setCipher(CipherInterface* cipher, string cipherName);

#endif