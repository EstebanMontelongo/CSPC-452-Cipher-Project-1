#ifndef __MAIN_FUNCTIONS__
#define __MAIN_FUNCTIONS__
#define REQ_ARGS 6	

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <algorithm>

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
 
/* Creating a enum values for ciphers. */
enum cipherValue {PLF, RTS, RFC, VIG, CES, HILL, UNKNOWN};

/* Create key-value pair between string and the cipher value. */
const unordered_map<string, cipherValue> cipherNames = { make_pair("PLF", PLF), make_pair("RTS", RTS),
                                                         make_pair("RFC", RFC), make_pair("VIG", VIG), 
                                                         make_pair("CES", CES),  make_pair("HILL", HILL) }; 

/* Function prototypes */
bool validNumArgs(int argc);
void findCipher(CipherInterface* &cipher, string cipherName);
void setCipher(CipherInterface* &cipher);
void readFile(string filename, string &text);
void writeFile(string fileName, string &text);
cipherValue stringToValue(string cipherName);
void toUpperString(string &str);

#endif