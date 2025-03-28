// This function eliminates the white space and comments in the .asm file

#include "cleanfile.h"
#define BUFFER_SIZE 256

int cleanfile(char line[], FILE *inputFile, FILE *outputFile)
{

    // Read each line from the input file and write it to the temporary file
    // If there's a space or // stops writing
    while (fgets(line, BUFFER_SIZE, inputFile))
    {
        if (strlen(line) > 1)
        {
            int i = 0;
            while (line[i] != '/' && line[i] != ' ' && line[i] != '\0')
            {
                fputc(line[i], outputFile);  // Write the character to the temporary file
                if (line[i+1] == ' ')
                {
                    fputc('\n', outputFile);  // Add a newline character after writing the line
                } 
                i++;
            }
        }
    }

    // Check if the end of the file was reached
    if (feof(inputFile))
    {
        printf("End of input file reached\n");
    }
    return 0;
    
}