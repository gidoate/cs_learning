// This function creates the symbol table for the assembler

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
int symboltable(char line[], FILE *inputFile, FILE *outputFile);

typedef struct {
    char symbol[50]; // Array to store the name
    int address;    // Variable to store the number
} SymbolTable;


#endif // SYMBOLTABLE_H