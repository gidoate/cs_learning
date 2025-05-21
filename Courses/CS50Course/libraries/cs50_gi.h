#ifndef cs50_gi_H
#define cs50_gi_H 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define a new data type for strings
typedef struct {
    char *data;
    size_t length;
} string;

// This function makes all characters capital leters
void alltocapital(char* word);

// Function to initialize a new String
string createString(const char *initialData);

// Function to free the memory allocated for a String
void freeString(string *str);

// Function to print a String
void printString(const string *str);


#endif // CS50_H