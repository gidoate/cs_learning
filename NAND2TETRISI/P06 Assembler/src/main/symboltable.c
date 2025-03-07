// This function creates the symbol table for the assembler

#include "symboltable.h"
#define BUFFER_SIZE 256

int symboltable(char line[], FILE *inputFile, FILE *outputFile)
{
    // Introduce the predefined values in the table from positions 0 to 22
    SymbolTable symbols[100] =
    {
        {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3},
        {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
        {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11},
        {"R12", 12}, {"R13", 13}, {"R14", 14}, {"R15", 15},
        {"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3},
        {"THAT", 4}, {"SCREEN", 16384}, {"KBD", 24576}
    };
    // Next symbol shall come in the position 23 of the table
    int next_symnum = 23;

    // Read each line from the input file, get symbols, add to the table and write it to the new temporary file the line
    // If the line starts with '(' , don't write it
    while (fgets(line, BUFFER_SIZE, inputFile))
    {
        int i = 0;
        if (line[i] == '(')
        {
            while (line[i] != ')')
            {
                
            }
            
        }
    }
}
