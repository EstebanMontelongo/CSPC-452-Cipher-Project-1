#include "MainHelperFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
	CipherInterface* cipher = NULL;
	string cipherName;
	string cryptoKey;
	string inputFileName;
	string outFileName;
	string choiceEncDec;
	bool keySet = false;

	
	try {
		/* Checks for invalid number of arguements */
		checkNumArgs(argc);

		/* Assigns values if valid number of arguments */
		cipherName = argv[1];
		cryptoKey = argv[2];
		inputFileName = argv[3];
		outFileName = argv[4];
		choiceEncDec = argv[5];

		/* Checks some of the other arguements */
		checkArgs(cipherName, choiceEncDec, inputFileName, outFileName);
	}
	catch (ExceptionError error) {
		displayExeptionError(error);
		return 0;
	}	

	transform(cryptoKey.begin(), cryptoKey.end(), cryptoKey.begin(), toupper);
	setCipher(cipher, cipherName);

	/* if cipher is null failed to allocate */
	if (!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	else {
		
		/* Attempt to set the key */
		try {
			keySet = cipher->setKey(cryptoKey);
		}
		catch (ExceptionError error) {
			displayExeptionError(error);
		}
		
		if (keySet) {
			/* Perform encryption */
			string cipherText = cipher->encrypt("hello world");
			cout << cipherText << endl;

			/* Perform decryption */
			string plainText = cipher->decrypt(cipherText);
			cout << plainText << endl;
		}
	
	}
	return 0;
}
