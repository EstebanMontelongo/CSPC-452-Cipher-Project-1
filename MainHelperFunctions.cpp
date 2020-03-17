#include "MainHelperFunctions.h"

//=======================================================================//
//    Description: This function will validate if the correct number of
//				   arguement has been entered.
//
//    Input: arc - the number of arguements entered in the command line		 
//    Output: true - if correct number of arguements; false otherwise
//======================================================================//
bool validNumArgs(int argc){
	if (argc != REQ_ARGS){

		cout << "You have entered " << argc << " argument" << ((argc > 1 || argc == 0) ? "s " : " ") <<
			"when " << REQ_ARGS << " are required." << endl;
		return false;
	}
	else{
		return true;
	}
}

//=======================================================================//
//    Description: This function will convert a string arguement into a
//				   cipher value.
//
//    Input: cipherName - the users cipher arguement
//    Output: cipherChoice - the string arguements cipher value 
//======================================================================//

cipherValue stringToValue(string cipherName){

	cipherValue cipherChoice = UNKNOWN;
	
	/* Make input all caps */
	transform(cipherName.begin(), cipherName.end(), cipherName.begin(), ::toupper);

	/* Checks to see if user input chiper exists. */
	if(cipherNames.find(cipherName) == cipherNames.end()){
		/* If it doesn't exist throw exception. */
		throw INVALID_CIPHER_NAME;
	}
	else
	{
		/* If it does exist assign it value from the map. */
		cipherChoice = cipherNames.find(cipherName)->second;
	}

	return cipherChoice;
}

//=======================================================================//
//    Description: This function will set the proper cipher instance.
//
//    Input: cipher - cipher refrence that will be assigned
//			 cipherChoice - cipher value that determines what
// 							class to choose.
//    Output: none
//======================================================================//

void setCipher(CipherInterface* &cipher, cipherValue cipherChoice){
	/* Assigns the peoper cipher instance. */
	switch (cipherChoice) {
		case PLF:
			cipher = new Playfair();
			break;
		case RTS: 
			cipher = new RowTransposition();
			break;
		case RFC:
			cipher = new Railfence();
			break;
		case VIG:
			cipher = new Vigenere();
			break;
		case CES:
			cipher = new Caesar();
			break;
		case HILL:
			cipher = new HillCipher();
			break;
		default:
			break;
	}
	/* if cipher is null failed to allocate */
	if (!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
}

//=======================================================================//
//    Description: This function will find and set the proper
//				   cipher class.
//
//    Input: cipher - cipher refrence that will be assigned
//			 cipherChoice - cipher value that determines what
// 							class to choose.
//    Output: none
//======================================================================//

void findCipher(CipherInterface* &cipher, string cipherName) {
	setCipher(cipher, stringToValue(cipherName));
}

//=======================================================================//
//    Description: This function will read a file and assign it to a 
//				   a string named text.
//
//    Input: filename - the file name to look for
//			 text - the location in which the file will be read into
//    Output: none
//======================================================================//
 void readFile(string filename, string &text){
    ifstream myFile(filename);
    string line;

	if (myFile.fail())
	{
		cout << "Unable to open file" << endl;
		throw INVALID_INPUT_FILE;
	}
	else
	{
		while(getline(myFile, line))
		{ 
			text.append(line);
		}
		myFile.close();
	}
}
//=======================================================================//
//	Description: Prints out enc/dec text into a file
//               
//	Input: fileName - the file will be name this string
//		   text - the dec/enc data

//	Output: none
//======================================================================//
void writeFile(string fileName, string &text){
	//Prints out to a file 
    ofstream oFile;
    oFile.open(fileName);
	if(oFile.fail()){
		cout << "Unable to create file " << endl;
		throw INVALID_OUTPUT_FILE;
	}
	else{
		oFile << text << endl;
	}   
	oFile.close();
}

//=======================================================================//
//	Description: This function converts a string to all capital letters
//
//	Input: str - string that will be made into all caps
//
//	Output: none
//======================================================================//
void toUpperString(string & str){
	/* Sets users key to all caps */
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}