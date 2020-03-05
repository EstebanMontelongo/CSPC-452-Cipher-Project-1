#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "vigenere.h"


using namespace std;

Vigenere::Vigenere(){
    SetAlphabet(string {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=~!@#$%^&*()_+[]{};':\",./<>?|\\ \t"});
    SetPlainText(string{"plaintext"});
    SetKey(string{"key"});
}

void Vigenere::SetAlphabet(string alpha){
    alphabet_ = alpha;
    SetAlphaMap();
    SetCharMap();
}

void Vigenere::SetAlphaMap(){
    for(unsigned int  i = 0; i < alphabet_.size(); i++){
        alphaMap_[alphabet_[i]] = i;
    }
}
void Vigenere::SetCharMap(){
    for(unsigned int  i = 0; i < alphabet_.size(); i++){
        charMap_[i] = alphabet_[i];
    }
}

void Vigenere::SetPlainText(string plainText){
    plainText_ = plainText;
}

void Vigenere::SetEncryptedText(){
    encryptedText_ = Encrypt();
}

void Vigenere::SetKey(string key){
    key_= key;
    SetAutoKey();
    SetEncryptedText();
}

void Vigenere::SetAutoKey(){
    autoKey_ = GenerateAutoKey();
}

string Vigenere::GenerateAutoKey(){
    string autoKey = "";
    if(key_.size() < plainText_.size()){
        autoKey = key_;
        for(unsigned int i = 0; i < plainText_.size() - key_.size(); i++){
            autoKey.push_back(plainText_[i]);
        }
    }
    else if(key_.size() > plainText_.size()){
        for(unsigned int i = 0; i < plainText_.size(); i++){
            autoKey.push_back(key_[i]);
        }
    }
    else if(key_.size() == plainText_.size()){
        autoKey = key_;
    }

    return autoKey;
}

int Vigenere::FindIndex(char c){
    if(alphaMap_.find(c) != alphaMap_.end()){
        return (alphaMap_.find(c))->second;
    }
    return {};
}
char Vigenere::FindCharacter(int index){
    if(charMap_.find(index) != charMap_.end()){
        return (charMap_.find(index))->second;
    } 
    return {};
}

string Vigenere::Encrypt(){
    string encryptedText = "";
    for(unsigned int  i = 0; i < plainText_.size(); i++){
        int index = FindIndex(plainText_[i]);
        int offset = FindIndex(autoKey_[i]);
        char newChar = FindCharacter((index+offset)%alphabet_.size());
        encryptedText.push_back(newChar);
    }
    return encryptedText;
}

string Vigenere::Decrypt(){
    string decryptedText = "";

    for(unsigned int  i = 0; i < encryptedText_.size(); i++){
        int index = FindIndex(encryptedText_[i]);
        int offset = FindIndex(autoKey_[i]);
        char newChar = FindCharacter( (alphabet_.size() + (index - offset)) % alphabet_.size());
        decryptedText.push_back(newChar);
    }
    return decryptedText;

}
