#include "Playfair.h"



Playfair::Playfair(){
    alphabet_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    playfairMatrix.resize(5);
    for (int i = 0; i < 5; ++i) {
        playfairMatrix[i].resize(5);
    }
}


//=======================================================================//
//	Description: This function converts a string to all capital letters
//
//	Input: str - string that will be made into all caps

//	Output: string which is all caps
//======================================================================//
string Playfair::toUpperString(const string & str){
	/* Sets users key to all caps */
	string newStr = str;
	transform(newStr.begin(), newStr.end(), newStr.begin(), ::toupper);
	return newStr;
}

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key)
{
    /* key must also be in range 1 <= key.size() <= 25,
         * so it key length must be 1 <= key.size() <= 2 */
        if( 0 >= key.size() || key.size() >= 26){
            return false;
        }

        /* Scans each character and check if its a digit
         * if a non digit is found return false, invalid key */
        for(auto c : key){
            if(!isdigit(c)){
            return false;
            }
        }
	key_ = toUpperString(key);
	createPlayfairMatrix();
    setKeyMap();
    printMatrix();
	return false;
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{
    string plainText = plaintext;
    vector<int> coordinates;
    int x1, x2, y1, y2;
	for(unsigned int i = 0; i < plainText.size() - 1; i+=2) {
        coordinates = keyMap[plainText[i]];
        x1 = coordinates[0];
        y1 = coordinates[1];
        coordinates = keyMap[plainText[i+1]];
        x2 = coordinates[0];
        y2 = coordinates[1];

        if(x1 != x2 && y1 != y2){
            plainText[i] = playfairMatrix[x1][y2];
            plainText[i+1]  = playfairMatrix[x2][y1];
        }
        else if(y1 == y2){
            x1 = (x1 + 1) % 5;
            x2 = (x2 + 1) % 5;
            plainText[i] = playfairMatrix[x1][y1];
            plainText[i+1]  = playfairMatrix[x2][y2];
        }
        else if(x1 == x2){
            y1 = (y1 + 1) % 5;
            y2 = (y2 + 1) % 5;
            plainText[i] = playfairMatrix[x1][y1];
            plainText[i+1]  = playfairMatrix[x2][y2];
        }
    }
    return plainText;
}

/*
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& ciphertext)
{
    string cipherText = ciphertext;
    vector<int> coordinates;
        int x1, x2, y1, y2;
    	for(unsigned int i = 0; i < cipherText.size() - 1; i+=2) {
            coordinates = keyMap[cipherText[i]];
            x1 = coordinates[0];
            y1 = coordinates[1];
            coordinates = keyMap[cipherText[i+1]];
            x2 = coordinates[0];
            y2 = coordinates[1];

            if(x1 != x2 && y1 != y2){
                cipherText[i] = playfairMatrix[x1][y2];
                cipherText[i+1]  = playfairMatrix[x2][y1];
            }
            else if(y1 == y2){
                x1 = (x1 + 1) % 5;
                x2 = (x2 + 1) % 5;
                cipherText[i] = playfairMatrix[x1][y1];
                cipherText[i+1]  = playfairMatrix[x2][y2];
            }
            else if(x1 == x2){
                y1 = (y1 + 1) % 5;
                y2 = (y2 + 1) % 5;
                cipherText[i] = playfairMatrix[x1][y1];
                cipherText[i+1]  = playfairMatrix[x2][y2];
            }
        }
        return cipherText;
}

void Playfair::createPlayfairMatrix()
{
    for(unsigned int i = 0; i < key_.size(); i++) {
        for(int j = 0; j < alphabet_.size(); j++) {
            if(key_[i] == alphabet_[j]) {
                alphabet_.erase(j, 1);
            }
        }
    }
    key_.append(alphabet_);
    int index = 0;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 5; column++) {
            playfairMatrix[row][column] = key_[index];
            index++;
        }
    }
}



/*
* Prints the Playfair matrix
* @param fp - the file pointer
*/

void Playfair::printMatrix() {
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 5; column++) {
            cout << playfairMatrix[row][column] << " ";
        }
        cout << endl;
    }

}

void Playfair::setKeyMap(){
    int index = 0;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 5; column++) {
            keyMap[key_[index]] = vector<int> {row , column};
            index++;
        }
    }
}

