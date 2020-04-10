#include "Playfair.h"


//=======================================================================//
//	Description: Deafult constructor.
//
//	Input: none
//
//	Output: none
//======================================================================//
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
//
//	Output: string which is all caps
//======================================================================//
string Playfair::toUpperString(const string & str){
	/* Sets users key to all caps */
	string newStr = str;
	transform(newStr.begin(), newStr.end(), newStr.begin(), ::toupper);
	return newStr;
}

//=======================================================================//
//	Description: This function constructs proper key and removes necessary 
//               letters from the alphabet(Since I == J).
//
//	Input: str - string that will be sanitized to in order for plarfair 
//               to work properley.
//	Output: string which is all caps
//======================================================================//
string Playfair::makeKey(const string &key){
    string newKey;
    unordered_set<char> exists;

    // Removes repeated characters from a string
    for(auto c: key){
        if(exists.insert(c).second){
            newKey.push_back(c);
        }
    }

    /* Key contains both I and J, remove J from the string and alphabet*/
    if(exists.find('J') != exists.end() && exists.find('I') != exists.end()){
        alphabet_.erase(alphabet_.find_first_of('J'), 1);
        newKey.erase(newKey.find_first_of('J'), 1);
    }
    /* Key contains I, remove J from the alphabet */
    else if(exists.find('I') != exists.end()){
        alphabet_.erase(alphabet_.find_first_of('J'), 1);
    }
    /* Key contains J, remove I from the alphabet */
    else if(exists.find('J') != exists.end()){
        alphabet_.erase(alphabet_.find_first_of('I'), 1);
    }
    /* Key contains neither I or J and since I == J remove J 
     * from the alphabet */
    else{
        alphabet_.erase(alphabet_.find_first_of('J'), 1);
    }

    return newKey;
}

//=======================================================================//
//	Description: This function sets the key for playfiar, generates matrix
//               and displays the matrix.
//
//	Input: str - string that will be made into all caps
//
//	Output: string which is all caps
//======================================================================//
bool Playfair::setKey(const string& key)
{

    string newKey = toUpperString(key);
    /* Scans each character and check if its a digit
     * if a non digit is found return false, invalid key */
    for(auto c : newKey){
        if(isdigit(c)){
        return false;
        }
    }

    /* Creates a proper key ans set it. */
	key_ = makeKey(newKey);

    /* key must also be in range 1 <= key.size() <= 25 */
    if( key_.size() <= 0 || key_.size() >= 26){
        return false;
    }

    /* Creates Play fair matrix */
	createPlayfairMatrix();

    /* Sets every value in matrix to its coordinates 
     * for easy access */
    setKeyMap();

    /* Displays the created matrix */
    printMatrix();
	return true;
}


//=======================================================================//
//	Description: Encrypts a plaintext string
//
//	Input: plaintext - the plaintext string
//
//	Output: the encrypted ciphertext string
//======================================================================//
string Playfair::encrypt(const string& plaintext)
{
    string plainText = toUpperString(plaintext);
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

//=======================================================================//
//	Description: Decrypts a string of ciphertext
//
//	Input: cipherText - the ciphertext
//
//	Output: the plaintext
//======================================================================//
string Playfair::decrypt(const string& ciphertext)
{
    string cipherText = toUpperString(ciphertext);
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
                x1 = ((x1 - 1) >= 0) ? (x1 - 1) % 5 : 4;
                x2 = ((x2 - 1) >= 0) ? (x2 - 1) % 5 : 4; 
                cipherText[i] = playfairMatrix[x1][y1];
                cipherText[i+1]  = playfairMatrix[x2][y2];
            }
            else if(x1 == x2){
                y1 = ((y1 - 1) >= 0) ? (y1 - 1) % 5 : 4;
                y2 = ((y2 - 1) >= 0) ? (y2 - 1) % 5 : 4; 
                cipherText[i] = playfairMatrix[x1][y1];
                cipherText[i+1]  = playfairMatrix[x2][y2];
            }
        }
        return cipherText;
}

//=======================================================================//
//	Description: Creates the playfair matrix key.
//
//	Input: none
//
//	Output: none
//======================================================================//
void Playfair::createPlayfairMatrix()
{
    string endKey = "";
    unordered_set<char> keySet;

    for(auto c : key_){
        keySet.insert(c);
    }

    /* Adds only character not in key to endKey */
    for(auto c : alphabet_){
        if(keySet.find(c) == keySet.end()){
            endKey.push_back(c);
        }
        
    }

    key_.append(endKey);
    /* Assigns the playfair matrix. */
    int index = 0;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 5; column++) {
            playfairMatrix[row][column] = key_[index];
            index++;
        }
    }
}

//=======================================================================//
//	Description: Prints the Playfair matrix
//
//	Input: none
//
//	Output: none
//======================================================================//
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

