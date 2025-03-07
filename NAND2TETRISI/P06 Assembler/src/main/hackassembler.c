#include <stdio.h>
#include <stdlib.h>
#include "cleanfile.h"
#include "parser.h"
#include "symboltable.h"

int main(int argc, char *argv[])
{
    printf("Initializing the assembly process...\n");
    // Check if the filename is provided as an argument
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // Else, continue with reading the file
    FILE *inputFile;
    FILE *cleanFile;
    FILE *symbolsFile;
    char line[256]; // Max amount of characters per line is 255 + NUL terminator
    const char *cleanFileName = argv[2]; // Clean file to be created
    const char *symbolsFileName = argv[2]; // File with symbols introduced into table and '()' deleted
    int linenum = 0; // Number of the line of the file that's being read
    // Open the file for reading - reading mode, the file must exist (r)
    inputFile = fopen(argv[1], "r"); 
    if (inputFile == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    // Open the temporary file for writing
    cleanFile = fopen(cleanFileName, "w");
    if (cleanFile == NULL)
    {
        perror("Error creating temporary file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    // Clean file from whitespace and comments
    cleanfile(line, inputFile, cleanFile);
    // Close the input file
    fclose(inputFile);
    // Create the symbol table
    //symboltable(line, cleanFile, symbolsFile);



    /* REMOVE the cleanFile
    if (remove(cleanFileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }
    */

    printf("Assembly process completed sucessfully\n");    
    return 0;
}