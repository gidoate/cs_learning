#include "symboltable.h"
#define BUFFER_SIZE 256

// Function to create and initialize a new symbol table
SymbolTable* createSymbolTable()
{
    SymbolTable *st = (SymbolTable *)malloc(sizeof(SymbolTable));
    st->size = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        st->table[i] = NULL;
    }

    // Introduce the predefined values in the table from positions 0 to 22
    addSymbol(st, "R0", 0);
    addSymbol(st, "R1", 1);
    addSymbol(st, "R2", 2);
    addSymbol(st, "R3", 3);
    addSymbol(st, "R4", 4);
    addSymbol(st, "R5", 5);
    addSymbol(st, "R6", 6);
    addSymbol(st, "R7", 7);
    addSymbol(st, "R8", 8);
    addSymbol(st, "R9", 9);
    addSymbol(st, "R10", 10);
    addSymbol(st, "R11", 11);
    addSymbol(st, "R12", 12);
    addSymbol(st, "R13", 13);
    addSymbol(st, "R14", 14);
    addSymbol(st, "R15", 15);
    addSymbol(st, "SP", 0);
    addSymbol(st, "LCL", 1);
    addSymbol(st, "ARG", 2);
    addSymbol(st, "THIS", 3);
    addSymbol(st, "THAT", 4);
    addSymbol(st, "SCREEN", 16384);
    addSymbol(st, "KBD", 24576);

    return st;
}

// Function to compute a hash value for a given string
unsigned int hash(char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Function to add a symbol and its address to the symbol table
void addSymbol(SymbolTable *st, char *symbol, int address)
{
    unsigned int index = hash(symbol);
    while (st->table[index] != NULL)
    {
        if (strcmp(st->table[index]->symbol, symbol) == 0)
        {
            st->table[index]->address = address;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    st->table[index] = (Symbol *)malloc(sizeof(Symbol));
    st->table[index]->symbol = strdup(symbol);
    st->table[index]->address = address;
    st->size++;
}

// Function to get the address of a symbol from the symbol table
int getAddress(SymbolTable *st, char *symbol)
{
    unsigned int index = hash(symbol);
    while (st->table[index] != NULL)
    {
        if (strcmp(st->table[index]->symbol, symbol) == 0)
        {
            return st->table[index]->address;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1; // Symbol not found
}

// Function to free the memory allocated for the symbol table
void freeSymbolTable(SymbolTable *st)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (st->table[i] != NULL)
        {
            free(st->table[i]->symbol);
            free(st->table[i]);
        }
    }
    free(st);
}

// Function to process the cleaned file and add labels to the symbol table
void processFile(SymbolTable *st, FILE *file)
{
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[256];
    int address = 0;

    while (fgets(line, BUFFER_SIZE, file))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Check if the line is a label (starts with '(' and ends with ')')
        if (line[0] == '(')
        {
            printf("we are in processFile2\n");
            // Extract the label name
            line[strlen(line) - 1] = 0; // Remove the closing ')'
            addSymbol(st, line + 1, address); // Add the label to the symbol table
            printf("Added label: %s at address %d\n", line + 1, address); // Debugging output
        }
        // Check if the line starts with '@' followed by a letter
        else if (line[0] == '@' && isalpha(line[1]))
        {
            printf("we are in processFile3\n");
            // Extract the symbol name
            addSymbol(st, line + 1, address); // Add the symbol to the symbol table
            printf("Added symbol: %s at address %d\n", line + 1, address); // Debugging output
            address++; // Increment the address for the symbol
        }
        else
        {
            printf("we are in processFile4\n");
            address++; // Increment the address for each instruction
        }
    }
    printf("we are in processFile5\n");
    fclose(file);
}

// Function to print the contents of the symbol table
void printSymbolTable(SymbolTable *st)
{
    printf("Symbol Table:\n");
    printf("Name\tAddress\n");
    printf("-----------------\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (st->table[i] != NULL)
        {
            printf("%s\t%d\n", st->table[i]->symbol, st->table[i]->address);
        }
    }
}