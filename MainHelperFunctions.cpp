#include "MainHelperFunctions.h"

void checkNumArgs(int argc)
{
	ErrorHandling test;
	if (argc != REQ_ARGS) {
		cout << "You have entered " << argc << " argument" << (argc > 1 || argc == 0) ? "s " : " " <<
			"when " << REQ_ARGS << " are required." << endl;
		throw INVALID_FORMAT;
	}
}

void checkArgs(string &cipherName, string  &ENC_DEC, string  &inputFile, string  &outFile)
{
	/* Handles invalid cipher name selection */
	/* ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE> */


	/* Handles invalid */
	return;
}

void setCipher(CipherInterface* cipher, string cipherName) {
	switch (cipherName) {
	case "PLF":
		*cipher = new Playfair();
		break;
	case "RTS": 
		*cipher = new RowTransposition();
		break;
	case "RFC":
		*cipher = new Railfence();
		break;
	case "VIG":
		*cipher = new Vigenere();
		break;
	case "CES":
		*cipher = new Caesar();
		break;
	case "HILL":
		*cipher = new HillCipher();
		break;
	default:
		throw INVALID_CIPHER_NAME;
		break;
	}
}
