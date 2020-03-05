#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;


int main()
{
    string plainText = "";
    string key = "";
    string encryptedText = "";
    string decryptedText = "";
    Vigenere vigenere1;

    cout << "Enter a plain text: ";
    getline(cin, plainText);

    cout << "Enter a key: ";
    getline(cin, key);

    vigenere1.SetPlainText(plainText);
    vigenere1.SetKey(key);

    encryptedText = vigenere1.Encrypt();
    decryptedText = vigenere1.Decrypt();

    cout << "Plain text is: "<< plainText << endl;
    cout << "Encrypted text is: "<< encryptedText << endl;
    cout << "Decrypted text is: " << decryptedText << endl;

    return 0;

}
