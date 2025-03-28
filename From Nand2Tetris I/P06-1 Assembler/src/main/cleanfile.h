// This function eliminates the white space and comments in the .asm file

#ifndef CLEANFILE_H
#define CLEANFILE_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
int cleanfile(char line[], FILE *inputFile, FILE *outputFile);

#endif // CLEANFILE_H