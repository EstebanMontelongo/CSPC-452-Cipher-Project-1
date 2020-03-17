#include "HillCipher.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */

vector<int> hillVect;
int hillMatrix[2][2];

bool HillCipher::setKey(const string& key)
{
	int i;

	stringstream strstream(key);
	// ignore comma found after each key
	while (strstream >> i)
    {
		hillVect.push_back(i);
		if (strstream.peek() == ','){
			strstream.ignore();
		}
    }
	return true;
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string HillCipher::encrypt(const string& plainText)
{
	string encryptedText ="", newpText = "";
	int l1, l2, index1=0, index2=1, newL1, newL2, temp;

	// insert key into hillMatrix
	for (int x=0; x<2; x++)
	{
		for (int y=0; y<2; y++)
		{
			temp = x*2 + y;
			hillMatrix[x][y] = hillVect.at(temp);
		}
	}

	// plainText string has pairs of 2 letters, if there's an odd letter, add Z to it
	if (!(plainText.length() % 2 == 1))
      newpText = plainText;
	else
			newpText = plainText + "Z";

	while ( newpText.length() > encryptedText.length() )
	{
		l1 = int(newpText[index1]) - 65;
		l2 = int(newpText[index2]) - 65;

		newL1 = (l1 * hillMatrix[0][0] + l2 * hillMatrix[0][1]) % 26 + 65;
		newL2 = (l1 * hillMatrix[1][0] + l2 * hillMatrix[1][1]) % 26 + 65;

		encryptedText = encryptedText + char(newL1) + char(newL2);

		index1 = index1 + 2;
		index2 = index2 + 2;

	}

	return encryptedText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string HillCipher::decrypt(const string& cipherText)
{
	string decryptedText ="";


	int determinant, k, factor, inverseMat[2][2], l1, l2, index1=0, index2=1, newL1, newL2;

	// calculate determinant
	determinant =  hillVect.at(0)*hillVect.at(3) - hillVect.at(1)*hillVect.at(2);
	factor = 27 / determinant;

	// calculate hillMatrix inverse
	inverseMat[0][0]= hillVect.at(3) ;
	inverseMat[0][1]= -1*hillVect.at(1);
	inverseMat[1][0]= -1*hillVect.at(2);
	inverseMat[1][1]= hillVect.at(0);

	// insert inverse hillMatrix into vector
	for (int z=0; z<2; z++)
	{
		for (int w=0; w<2; w++)
		{
			inverseMat[z][w]=(factor*(inverseMat[z][w]%26)) %26 ;
			if (inverseMat[z][w] < 0)
				inverseMat[z][w]= inverseMat[z][w] + 26;
		}
	}

	while ( cipherText.length() > decryptedText.length() )
	{
		l1 = int(cipherText[index1]) - 65;
		l2 = int(cipherText[index2]) - 65;

		newL1 = (l1 * inverseMat[0][0] + l2 * inverseMat[0][1]) % 26 + 65;
		newL2 = (l1 * inverseMat[1][0] + l2 * inverseMat[1][1]) % 26 + 65;

		decryptedText = decryptedText + char(newL1) + char(newL2);

		index1 = index1 + 2;
		index2 = index2 + 2;
	}

	return decryptedText;
}

