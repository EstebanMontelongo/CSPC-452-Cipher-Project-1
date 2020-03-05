#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>


using namespace std;

class Vigenere{
    public:
    Vigenere();
    void SetPlainText(string plainText);
    void SetKey(string key);
    void SetAlphabet(string alpha);

    string Encrypt();
    string Decrypt();

    private:
    string plainText_;
    string autoKey_;
    string key_;
    string alphabet_;
    string encryptedText_;
    unordered_map<char, int> alphaMap_;
    unordered_map<int, char> charMap_;

    void SetAlphaMap();
    void SetCharMap();
    void SetAutoKey(); 
    void SetEncryptedText();
    string GenerateAutoKey();
    int FindIndex(char c);
    char FindCharacter(int index);

};