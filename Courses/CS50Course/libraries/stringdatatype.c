#include <cs50_gi.h>

// Define a new data type for strings
typedef struct {
    char *data;
    size_t length;
} string;

// Function to initialize a new String
string createString(const char *initialData) {
    string newString;
    newString.length = strlen(initialData);
    newString.data = (char *)malloc((newString.length + 1) * sizeof(char));
    if (newString.data != NULL) {
        strcpy(newString.data, initialData);
    }
    return newString;
}

// Function to free the memory allocated for a String
void freeString(string *str) {
    if (str->data != NULL) {
        free(str->data);
        str->data = NULL;
        str->length = 0;
    }
}

// Function to print a String
void printString(const string *str) {
    if (str->data != NULL) {
        printf("%s\n", str->data);
    }
}

int main() {
    // Create a new String
    string myString = createString("Hello, World!");

    // Print the String
    printString(&myString);

    // Free the memory allocated for the String
    freeString(&myString);

    return 0;
}