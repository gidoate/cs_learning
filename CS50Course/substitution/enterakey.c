#include "enterakey.h"

bool isWord(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}
char* enterakey()
{
    bool validInput = false;
    static char key[26];
    do
    {
        scanf("%s", key); // Limit input to avoid buffer overflow

        if (isWord(key))
        {
            validInput = true;
        } else
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a word with letters only.\n");
        }
    } while (!validInput);
    return word;
}