#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

#include<iostream>


/* Enumeration list of errors. */
enum ExceptionError {
	INVALID_CIPHER_NAME,
	INVALID_KEY,
	INVALID_CRYPT,
	INVALID_INPUT_FILE,
	INVALID_OUT_FILE,
	INVALID_FORMAT,
	UNKNOWN_ERROR
};

/* Displays Error */
void displayExeptionError(ExceptionError error);

#endif