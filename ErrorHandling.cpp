#include "ErrorHandling.h"

/**
 * Function displays an error message.
 * @param error - the type of Exception error.
 * @return - none
 */
void displayExeptionError(ExceptionError error) {
	switch (error)
	{
	case INVALID_CIPHER_NAME:
		cout << "Invalid cipher name." << endl;
		break;
	case INVALID_KEY:
		cout << "Invalid cipher key. " << endl;
		break;
	case INVALID_CRYPT:
		cout << "Fourth arguement must be either DEC or ENC (Decrypt or Encrypt)." << endl;
		break;
	case INVALID_INPUT_FILE:
		cout << "Invalid Input File." << endl;
		break;
	case INVALID_OUT_FILE:
		cout << "Invalid Output File."
		break;
	case INVALID_FORMAT:
		cout << "Please enter the following format: \n" 
			<< "./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE> " << endl;
		break;
	default:
		break;
	}

	return;
}