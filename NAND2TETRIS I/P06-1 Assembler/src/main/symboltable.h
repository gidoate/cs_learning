// This function creates the symbol table for the assembler

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H 
#define TABLE_SIZE 100
#define BUFFER_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//------------------ Structure declarations ------------------//
/*
* Structure for the symbols and their address
*/
typedef struct {
    char *symbol;
    int address;
} Symbol;

// Structure for the symbol table
// Used to store an array of pointers to Symbol structures and an integer to keep track of the number of symbols
typedef struct {
    Symbol *table[TABLE_SIZE];
    int size;
} SymbolTable;

//------------------ Function prototypes declaration ------------------//
// Function to create and initialize a new symbol table
SymbolTable* createSymbolTable();

// Function to compute a hash value for a given string
unsigned int hash(char *str);

// Function to add a symbol and its address to the symbol table
void addSymbol(SymbolTable *st, char *symbol, int address);

// Function to get the address of a symbol from the symbol table
int getAddress(SymbolTable *st, char *symbol);

// Function to free the memory allocated for the symbol table
void freeSymbolTable(SymbolTable *st);

// Function to process the input file and add labels to the symbol table
void processFile(SymbolTable *st, FILE *file);

// Function to print the symboltable
void printSymbolTable(SymbolTable *st); 

#endif // SYMBOLTABLE_H