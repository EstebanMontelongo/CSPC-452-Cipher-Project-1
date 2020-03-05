#/bin/bash

# Shell script to compile source code and link object code to create a .out

rm *.o
rm *.out

echo "Compiling main.cpp..."
g++ -c -m64 -Wall -fno-pie -no-pie -o main.o main.cpp

echo "Compiling vigenere.cpp..."
g++ -c -m64 -Wall -fno-pie -no-pie -o vigenere.o vigenere.cpp

echo "Link the object files..."
g++ -m64 -fno-pie -no-pie -o Vigenere.out vigenere.o main.o 

echo "Executing Program..."
echo " "
./Vigenere.out
