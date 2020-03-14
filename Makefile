all:	cipher
 
cipher:	cipher.o Playfair.o Caesar.o Railfence.o RowTransposition.o Vigenere.o HillCipher.o ErrorHandling.o MainHelperFunctions.o
	g++ cipher.o Playfair.o Caesar.o Railfence.o RowTransposition.o Vigenere.o HillCipher.o ErrorHandling.o MainHelperFunctions.o -o cipher

cipher.o:	cipher.cpp
	g++ -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h 
	g++ -g -c Playfair.cpp

Caesar.o:	Caesar.cpp Caesar.h CipherInterface.h 
	g++ -g -c Caesar.cpp

Railfence.o:	Railfence.cpp Railfence.h CipherInterface.h 
	g++ -g -c Railfence.cpp

RowTransposition.o:	RowTransposition.cpp RowTransposition.h CipherInterface.h 
	g++ -g -c RowTransposition.cpp

Vigenere.o:	Vigenere.cpp Vigenere.h CipherInterface.h 
	g++ -g -c Vigenere.cpp

HillCipher.o: HillCipher.cpp HillCipher.h CipherInterface.h 
	g++ -g -c HillCipher.cpp

ErrorHandling.o:	ErrorHandling.cpp ErrorHandling.h 
	g++ -g -c ErrorHandling.cpp

MainHelperFunctions.o: MainHelperFunctions.cpp MainHelperFunctions.h 
	g++ -g -c MainHelperFunctions.cpp

clean:
	rm -rf *.o cipher
