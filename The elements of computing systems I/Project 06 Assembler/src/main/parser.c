// This code reads the input, gets next command and provides access to each part of the command
#include "parser.h"

int parser(int argc, char *argv[])
{
    printf("Parsing the file...\n");
    FILE *outputFile;
    FILE *inputFile;
    char line[256]; // Max amount of characters per line is 255 + NUL terminator
    const char *outputFileName = "output.txt"; // File to be created

    // Open the file for reading - reading mode, the file must exist (r)
    inputFile = fopen(argv[1], "r"); 
    if (inputFile == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    // Open the temporary file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        perror("Error creating temporary file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Read each line from the input file, print it, and write it to the temporary file
    while (fgets(line, sizeof(line), inputFile))
    {
        printf("%s", line);  // Print the line from the original file
        if (line[0] != '/' && strlen(line) > 1)
        {
            fputs(line, outputFile);  // Write the line to the temporary file
        }   
    }

    // Check if the end of the file was reached
    if (feof(inputFile))
    {
        printf("\nEnd of file reached");
    }

    // Close the file
    fclose(inputFile);
    fclose(outputFile);

    // Reopen the temporary file for reading
    outputFile = fopen(outputFileName, "r");
    if (outputFile == NULL) 
    {
        perror("Error reopening temporary file");
        return EXIT_FAILURE;
    }

    // Read and print each line from the temporary file
    while (fgets(line, sizeof(line), outputFile))
    {
        printf("%s", line);  // Print the line from the temporary file
    }

    // Close the temporary file
    fclose(outputFile);
    printf("\nParsing completed");
    printf("\nOutput file created: %s\n", outputFileName);
}
